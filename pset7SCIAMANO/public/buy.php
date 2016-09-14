<?php

    //configuration
    require("../includes/config.php");
    
    //get user ID
    $userID = $_SESSION["id"];
    
    //get user current cash
    $userinfo = query("SELECT cash FROM users WHERE id = ?", $userID);
    $userinfoNarrow = $userinfo[0];
    $userCash = $userinfoNarrow["cash"];   //IMPORTANT! user balance!
    
    
     //if user reached page via GET
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
    
    render("buy_form.php", ["title" => "buy"]);
    
    }
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    
      //symbol empty
      if (empty($_POST["symbol"]))
      {
          apologize("ERROR: The symbol field is empty");
      }
      
      $symbolToBuy = $_POST["symbol"];
      
      if (empty($_POST["shares"]))
      {
          apologize("ERROR: The shares field is empty");
      }
          
      $sharesToBuy = $_POST["shares"]; 
          
      if (preg_match("/^\d+$/", $_POST["shares"]) == 0)
      {
          apologize("ERROR: The shares field must be non-negative and non-decimal");
      }
      
      //get info for current share
      
      $shareInfo = lookup($symbolToBuy);
      
      if ($userCash <  ($shareInfo["price"] * $sharesToBuy) )
      {
          apologize("Sorry, insufficient balance");
      }
      
      //add stock to portfolio
      
      $newCash = $userCash - ($shareInfo["price"] * $sharesToBuy);
      
      query("INSERT INTO portfolios (id, symbol, shares) VALUES( ?, ?, ?) 
             ON DUPLICATE KEY UPDATE shares = shares + ?", $userID , strtoupper($symbolToBuy) , $sharesToBuy, $sharesToBuy);
      query("UPDATE users SET cash = ? WHERE id = ?" , $newCash , $userID);
      
      query("INSERT INTO `pset7`.`history` (`id`, `transaction` , `time and date`, `symbol`, `shares`, `price`) VALUES (?, ? , CURRENT_TIMESTAMP, ?, ?, ?);"
      
             , $userID, "BUY" , strtoupper($symbolToBuy), $sharesToBuy, $shareInfo["price"]);
      
      redirect("/");
    }
    

?>
