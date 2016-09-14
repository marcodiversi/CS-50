<div>

<ul class="nav nav-pills">
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="history.php">History</a></li>
    <li><a href="changePass.php">Change Password</a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
</ul>

</div>

<div>
    <?php
        echo "<b>$username</b>" . "<em>'s Portfolio</em>";
    ?>
</div>

<table class="table table-bordered">
    <?php
    
        print("<tr>");
        print("<th>" . strtoupper("You currently own these stocks") . "</th>"); 
        print("</tr>");
        print("<tr>");
        print("<th>" . "Symbol" . "</th>");
        print("<th>" . "Company Name" . "</th>");
        print("<th>" . "Shares" . "</th>");
        print("<th>" . "Price per Share" . "</th>");
        print("<th>" . "TOTAL" . "</th>");
        print("</tr>");
        
        foreach($portfolio as $position)
        {
            $stockData = lookup($position["symbol"]);
            
            $total = ($stockData["price"] * $position["shares"]);
            $total = number_format($total, 2 , '.' , ',');
            
            if ($stockData !== false)
            {
                
                print("<tr>");
                print("<td>" . $position["symbol"] . "</td>");
                print("<td>" . $stockData["name"]  . "</td>");
                print("<td>" . $position["shares"] . "</td>");
                print("<td>" . $stockData["price"] . "</td>");
                print("<td>" . $total . " $</td>");
                print("</tr>");
            }
        }
 
    ?>
</table>

<div>
    <?php
        $balance = number_format($balance, 2 , '.' , ',');
        echo ("<h3>Your Balance is: <small><b>" . $balance . "$</b></small></h3>");
    ?>
</div>

<div>
    <a href="logout.php">Log Out</a>
</div>
