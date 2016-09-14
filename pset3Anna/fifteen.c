#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*BOOLEAN DEFINITIONS*/
typedef int bool;
#define true 	1
#define false 	0
/*********************/

/*COMMAND DEFINITIONS*/
#define CMD_INIT 	"init"
#define CMD_DRAW 	"draw"
#define CMD_MOVE 	"move"
#define CMD_WON 	"won"
#define CMD_BYE 	"bye"
/*********************/

/*DIRECTION DEFINITIONS*/
const char UP =	'u';
const char DOWN =	'd';
const char LEFT=	'l';
const char RIGHT =	'r';
/***********************/

/*ERROR DEFINITIONS*/
#define SUCCESS 			0
#define ERR_NULLPOINTER		9
#define ERR_INVALIDARG		8
#define ERR_INVALIDPOS		7
#define ERR_INVALIDDIR		6
#define ERR_INVALIDMOV		5
#define ERR_INVALIDCELL		4
/********************/

#define MIN_DIM		3

/*Global variables*/
int _dim=0, _tot_mov=0;
int * _matrix = NULL;
bool _init_game = false, _won= false;

/* Function Definitions*/
void program_exit();
void print_command();
void print_error(int err);

void readline(char * line, size_t * len,FILE * stream);
int rangeRand( int range_min, int range_max);

int init_game();
int draw();
int move(int position, char direction);
int won();

int main (int argc, char ** argv)
{
	char _cmd[20], * token = NULL;
	size_t _len_cmd = 0;
	int err, _position;
	char _direction;

	if(argc < 2)
	{
		printf("Syntax Error!\n To use: %s <dim>\n", argv[0]);
		printf(" To have a matrix  of <dim>*<dim> size.\n");
		program_exit();
	}

	_dim = atoi(argv[1]);
	if(_dim < MIN_DIM)
	{
		printf("Argument Invalid: dimension %d\n", _dim);
		printf("Dimension must be >= %d\n", MIN_DIM);
		program_exit();
	}
	
	/*Alloc Matrix*/
	_matrix = (int *) malloc(_dim*_dim*sizeof(int));
	memset(_matrix, 0, _dim*_dim*sizeof(int));
	/*set seed for random number*/
	srand(time(NULL));

	print_command();
	while(!_won )
	{
		readline(_cmd, &_len_cmd, stdin);
		
		if(_len_cmd > 2)
		{
			if(strncmp(_cmd, CMD_INIT, 4) == 0)
			{
				err = init_game();
				if(err != SUCCESS)
				{
					print_error(err);
				}
			}
			else if(strncmp(_cmd, CMD_DRAW, 4) == 0)
			{
				if(!_init_game)
				{
					printf("Init First!\n");
				}
				else
				{
					err = draw();
					if(err != SUCCESS)
					{
						print_error(err);
					}
				}
			}
			else if(strncmp(_cmd, CMD_MOVE, 4) == 0)
			{
				
				if(!_init_game)
				{
					printf("Init First!\n");
				}
				else
				{
					/* get the first token */
   					token = strtok(_cmd, " ");
   					/*Position*/
      				token = strtok(NULL, " ");
   					_position = atoi(token);
   					/*Direction*/
   					token = strtok(NULL, " ");
   					_direction = token[0];

					err = move(_position, _direction);
					if(err != SUCCESS)
					{
						print_error(err);
					}
					_tot_mov++;
				}
			}
			else if(strncmp(_cmd, CMD_WON, 3) == 0)
			{
				err = won();
				if(err != SUCCESS)
				{
					print_error(err);
				}
				if(_won)
					printf("You Win!! Congratulations!\n");
				else
					printf("Sorry!! Try moving other cells\n");
			}
			else if(strncmp(_cmd, CMD_BYE, 3) == 0)
			{
				if(_tot_mov == 0)
					printf("You did not play");
				else if(_tot_mov == 1)
					printf("You did %d move", _tot_mov);
				else
					printf("You did %d moves", _tot_mov);
				if(!_won)
					printf(" and you did not win");
				printf(".\n");
				program_exit();
			}
			else
			{
				print_command();
			}
		}
		else
		{
			print_command();
		}
	}

	program_exit();
}

int init_game()
{
	int size = _dim*_dim, i;
	int rnd, r_min, r_max;

	if(_matrix == NULL)
		return ERR_NULLPOINTER;
	if(_dim <  MIN_DIM)
		return ERR_INVALIDARG;

	r_min  = 1;
	r_max = size;
	for(i=0;i < size; i++)
		_matrix[i] = -1;

	for(i =0; i < size -1; i++)
	{
		do 
		{
			rnd = rangeRand(0, size-1);
		//	printf("%d\n ", rnd);
			if(_matrix[rnd] == -1)
			{
				/*To reduce the random range*/
				if(rnd == r_min)
					r_min++;
				if(rnd == r_max)
					r_max--;
			//	printf("min: %d max: %d\n", r_min, r_max);
				_matrix[rnd] = i+1;
				break;
			}
		}while(1);
	}

    _init_game = true;
	return SUCCESS;
}

int draw()
{
	int size,i;
	if(_matrix == NULL)
		return ERR_NULLPOINTER;
	if(_dim <  MIN_DIM)
		return ERR_INVALIDARG;

	size = _dim*_dim;
	for(i=0; i< size; i++)
	{
		if(_matrix[i] == -1)
			printf(" _ ");
		else
			printf(" %d ",_matrix[i]);
		if((i+1)%_dim == 0)
			printf("\n\n");
	}

	return SUCCESS;
}

int move(int position, char direction)
{
	int size;
	int idx;

	if(_matrix == NULL)
		return ERR_NULLPOINTER;
	if(_dim <  MIN_DIM)
		return ERR_INVALIDARG;

	size = _dim*_dim;
	if( position < 1 || position > size)
		return ERR_INVALIDPOS;

	if( direction != UP && direction != DOWN &&
		direction != LEFT && direction != RIGHT)
		return ERR_INVALIDDIR;
	idx = position-1;
	if(_matrix[idx] == -1)
		return ERR_INVALIDCELL;

	if(direction == UP)
	{
		if(position > 0 && position <= _dim)
			return ERR_INVALIDMOV;
		else if( _matrix[idx-_dim] != -1)
			return ERR_INVALIDMOV;
		/*move*/
		_matrix[idx-_dim] = _matrix[idx];
		_matrix[idx] = -1;
	}
	else if(direction == DOWN)
	{
		if(position > (size-_dim) && position <= size)
			return ERR_INVALIDMOV;
		else if( _matrix[idx+_dim] != -1)
			return ERR_INVALIDMOV;
		/*move*/
		_matrix[idx+_dim] = _matrix[idx];
		_matrix[idx] = -1;
	}
	else if(direction == RIGHT)
	{
		if(position%size == 0)
			return ERR_INVALIDMOV;
		if( _matrix[idx+1] != -1)
			return ERR_INVALIDMOV;
		/*move*/
		_matrix[idx+1] = _matrix[idx];
		_matrix[idx] = -1;
	}
	else if(direction == LEFT)
	{
		if((position+_dim-1)%size == 0)
			return ERR_INVALIDMOV;
		else if( _matrix[idx-1] != -1)
			return ERR_INVALIDMOV;
		/*move*/
		_matrix[idx-1] = _matrix[idx];
		_matrix[idx] = -1;
	}

	return SUCCESS;
}
int won()
{
	int size, i;

	if(_matrix == NULL)
		return ERR_NULLPOINTER;
	if(_dim <  MIN_DIM)
		return ERR_INVALIDARG;

	size = _dim*_dim;
	_won = true;
	for(i =0; i < size -1; i++)
	{
		if(_matrix[i] != (i+1))
		{
			_won = false;
			break;
		}
	}

	return SUCCESS;
}

void program_exit()
{
	if(_matrix != NULL)
		free(_matrix);

	printf("Bye Bye!\n");
	exit(0);
}

void print_command()
{
	printf("Use the follow command:\n");
	printf("\t init: to random initialize the matrix.\n");
	printf("\t draw: to draw the matrix on the screen.\n");
	printf("\t move <p> <%c|%c|%c|%c>: to move the cell in position <p>\n", UP,DOWN,LEFT,RIGHT);
	printf("\t                     up,down,right,left.\n");
	printf("\t won: to check if you won the game.\n");
	printf("\t bye: to exit from the game.\n");
	printf("\n");
}

void print_error(int err)
{
	switch(err)
	{
		case ERR_NULLPOINTER: 	printf("Error: Null Pointer.\n"); break;
		case ERR_INVALIDARG: 	printf("Error: Invalid Argument.\n"); break;
		case ERR_INVALIDPOS: 	printf("Error: Invalid Position.\n Cold be 1 <= <pos> <= %d.\n", _dim*_dim); break;
		case ERR_INVALIDDIR: 	printf("Error: Invalid Direction.\n Could be <%c|%c|%c|%c>.\n", UP, DOWN, LEFT, RIGHT); break;
		case ERR_INVALIDMOV: 	printf("Error: Invalid Moving.\n Draw the matrix to check the possible moving.\n"); break;
		case ERR_INVALIDCELL:	printf("Error: Invalid Cell.\n Selected to move the empty cell.\n"); break;
		default: 				printf("Error: Unknow Error.\n");
	}
}

void readline(char * line, size_t * len,FILE * stream)
{
	*len = 0;
	do
	{
		line[*len] = fgetc(stream);
		if(line[*len] == '\n')
		{
			line[*len] = '\0';
			(*len)++;
			break;
		}
		(*len)++;
	}while(1);

	return;
}

int rangeRand( int range_min, int range_max)
{
   // Generate random numbers in the half-closed interval
   // [range_min, range_max). In other words,
   // range_min <= random number < range_max
	return (double)rand() / (RAND_MAX) * (range_max - range_min)
            + range_min;
}