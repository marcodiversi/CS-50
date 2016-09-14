
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define BLANK 0

// directional constants
#define	UP 		1
#define	RIGHT 	2
#define	DOWN 	3
#define	LEFT 	4
#define	ILLEGAL	0

#define NUM_DIRECTIONS 4


#define	SENTINEL -1


#define	TILE_NOT_FOUND -1


int board[DIM_MAX][DIM_MAX];


int d;

void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int	get_direction(int tile_id);


void make_move(int tile_id, int direction);


int	get_col(int tile_id);


int	get_row(int tile_id);


int get_tile(int row, int col);


void set_tile(int row, int col, int tile_id);

int main(int argc, string argv[])
{
   
    if (argc != 2)
    {
        printf("Usage: %s d\n", argv[0]);
        return 1;
    }

 
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

 
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    
    greet();

  
    init();

   
    while (true)
    {
    
        clear();

    
        draw();

       
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);


        if (won())
        {
            printf("ftw!\n");
            break;
        }

        printf("Tile to move: ");
        int tile = GetInt();

     
        if (tile == 0)
        {
            break;
        }

    
        fprintf(file, "%i\n", tile);
        fflush(file);

      
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

      
        usleep(500000);
    }


    fclose(file);

 
    return 0;
}




void clear()
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}



void greet()
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

void init()
{
    int i, j;
    int counter = d * d;


    for (i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {
            set_tile(i, j, --counter);
        }
    }

    set_tile(d - 1, d - 1, BLANK);

   
    if (d % 2 == 0)
    {
        set_tile(d - 1, d - 3, 1);
        set_tile(d - 1, d - 2, 2);
    }
}




void draw()
{
    int i, j;
    printf("\n");
    for (i = 0; i < d; i++)
    {   
        printf(" ");
        for (j = 0; j < d; j++)
        {	
            if (get_tile(i, j) == BLANK)
            {
                printf("%3c", '_');
			}
            else
            {
                printf("%3d", get_tile(i, j));
			}
		}
        printf("\n\n");
	}
}


bool move(int tile_id)
{
    int direction;

    direction = get_direction(tile_id);

    if (direction != ILLEGAL)
    {
        make_move (tile_id, direction);
        return true;
    }
    else
    {
        return false;
    }  
}


bool won()
{
    int i, j;
    int counter = 1;
    int num_tiles = d * d;
    
    // the lower right hand corner must be the blank
    if (get_tile(d - 1, d - 1) != BLANK)
    {
        return false;
    }


    for (i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {
        
            if (counter == num_tiles)
            {
                return true;
            }
            else if (get_tile(i, j) != counter)
            {
                return false;
            }
            counter++;
        }
    }

 
    return false;
}


int get_direction(int tile_id)
{
  
    int p_row, p_col;
    

    int b_row, b_col;

 
    if ((tile_id <= 0) || (tile_id >= d * d))
    {
        return ILLEGAL;
    }


    p_row = get_row(tile_id);
    p_col = get_col(tile_id);
    b_row = get_row(BLANK);
    b_col = get_col(BLANK);


    if ((p_row == TILE_NOT_FOUND) || (p_col == TILE_NOT_FOUND) || 
        (b_row == TILE_NOT_FOUND) || (b_col == TILE_NOT_FOUND))
    {
        return ILLEGAL;
	}


    if ((p_row == b_row + 1) && (p_col == b_col))
    {
        return UP;
	}
    else if ((p_row == b_row - 1) && (p_col == b_col))
    {
        return DOWN;
	}
    else if ((p_row == b_row) && (p_col == b_col - 1))
    {
        return RIGHT;
	}
    else if ((p_row == b_row) && (p_col == b_col + 1))
    {
        return LEFT;
	}
    else
    {
        return ILLEGAL;
	}
}


void make_move(int tile_id, int direction)
{
    
    int row, col; 

 
    row = get_row(tile_id);
    col = get_col(tile_id);

  
    set_tile(row, col, BLANK);


    switch (direction)
    {
        case LEFT:
            set_tile(row, col - 1, tile_id);
            break;
        case RIGHT:
            set_tile(row, col + 1, tile_id);
            break;
        case UP:
            set_tile(row - 1, col, tile_id);
            break;
        case DOWN:
            set_tile(row + 1, col, tile_id);
            break;
        default:
            break;
	}
}


int get_col(int tile_id)
{
    int i, j;
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {
            if (get_tile(i, j) == tile_id)
            {
                return j;
			}
		}
	}

    return TILE_NOT_FOUND;
}

int get_row(int tile_id)
{
    int i, j;
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {
            if (get_tile(i, j) == tile_id)
            {
                return i;
			}
		}
	}

    return TILE_NOT_FOUND;
}


int get_tile(int row, int col)
{
    return board[row][col];
}

void set_tile(int row, int col, int tile_id)
{
    board[row][col] = tile_id;
}
