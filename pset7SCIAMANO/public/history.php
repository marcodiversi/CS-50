<?php

    // configuration
    require("../includes/config.php"); 
    
    
   $history = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);
   
   
  render("history_form.php" , ["title" => "History" , "historyArr" => $history ]);


?>
