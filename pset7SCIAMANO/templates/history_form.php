<table class="table table-bordered">

    <tbody>
    
        <?php
        
        print("<tr>");
        print("<th>" . strtoupper("Transaction History:") . "</th>"); 
        print("</tr>");
        print("<tr>");
        print("<th>" . "Transaction" . "</th>");
        print("<th>" . "Time and Date" . "</th>");
        print("<th>" . "Symbol" . "</th>");
        print("<th>" . "Shares" . "</th>"); 
        print("<th>" . "Price per Share" . "</th>");
        print("</tr>");
            
             foreach($historyArr as $position)
        {
                $pricee = number_format($position["price"], 2 , '.' , ',');
                print("<tr>");
                print("<td>" . $position["transaction"] . "</td>");
                print("<td>" . $position["time and date"]  . "</td>");
                print("<td>" . $position["symbol"] . "</td>");
                print("<td>" . $position["shares"] . "</td>");
                print("<td>" . $pricee . " $</td>");
                print("</tr>");
            
        }
 
    ?>
        
        
    
    </tbody>

</table>
