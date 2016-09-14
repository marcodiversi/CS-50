<?php
        //configuration
    require("../includes/config.php");
    
        //if user reached page via GET
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
    
       //else render form
       render("quote_form.php", ["title" => "quote"]);
    
    }
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
      //symbol empty
      if (empty($_POST["symbol"]))
      {
          apologize("ERROR: The symbol field is empty");

      }
      
      $stockSymbol = $_POST["symbol"];
      
      $stockData = lookup($stockSymbol);
      
      if ( $stockData === false)
      {
          apologize("ERROR: Try Again");
      }

      // display prices
      
      render("quote_display.php", [  "stockSymb" => $stockData["symbol"] , "stockName" => $stockData["name"] ,
              "stockPrice" => $stockData["price"] ]);
       
    }
?>
