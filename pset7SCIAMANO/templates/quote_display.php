
<?php
    
    $stockPrice = number_format($stockPrice, 2 , '.' , ',');
    
    print "<b>Symbol:</b>   " . strtoupper($stockSymb) . "<br>";
    print "<b>Name  :</b>   " . $stockName . "<br>";
    print "<b>Price :</b>   " . "$" . $stockPrice . "<br>";

?>
