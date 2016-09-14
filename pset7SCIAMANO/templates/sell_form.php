
<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class="form-control" name="symbol">
            <?php
                
               foreach ($portfolio as $position)
                {
                    print("<option value='" . $position["symbol"] . "'>" . $position["symbol"] . "</option> \n");

                }
            ?> 
            </select>     
        </div>
        
        <div class="form-group">
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    
    </fieldset>
</form>
