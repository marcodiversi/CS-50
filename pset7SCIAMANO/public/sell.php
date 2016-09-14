<?php

    // configuration
    require("../includes/config.php"); 
    
    
    //get ID of person
    
    $userID = $_SESSION["id"];
    
    //get his stock holdings
    
    $portfolioRows = query("SELECT * FROM portfolios WHERE id = ?" , $userID); // [id [symbol [shares

    
        // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("sell_form.php", ["title" => "Sell", "portfolio" => $portfolioRows]);
    }
    
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]))
      {
          apologize("ERROR: The symbol field is empty");
      }
      
      //update persons portfolio
      
      // set up variables
      
      $stockSymbol = $_POST["symbol"];
      
      $stockInfo = lookup($stockSymbol);  // [symbol] [name] [price]
      
      $sharesRaw = query("SELECT shares FROM portfolios WHERE id = ? AND symbol = ?", $userID , $stockSymbol);
      $shares = $sharesRaw[0];
      
      $earning =  ($stockInfo["price"] ) * $shares["shares"];
      
      //remove stock from portfolio and update cash

      query("DELETE FROM portfolios WHERE id = ? AND symbol = ?;", $userID , $stockSymbol);
      query("UPDATE users SET cash = cash + ? WHERE id = ?;" , $earning , $userID);
      
      query("INSERT INTO `pset7`.`history` (`id`, `transaction` , `time and date`, `symbol`, `shares`, `price`) VALUES (?, ? , CURRENT_TIMESTAMP, ?, ?, ?);"
      
             , $userID, "SELL" , strtoupper($stockSymbol), $shares["shares"], $stockInfo["price"]);

             
      redirect("/");
      
    }
    
?>
