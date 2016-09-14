<?php

    // configuration
    require("../includes/config.php"); 
    
    //get name and ID of user and store them in $usersRows , number 0 is the current selected by ID num
    $userID = $_SESSION["id"];
    
    $usersRows = query("SELECT * FROM users WHERE id = ?" , $userID);
    
    $usersRow = $usersRows[0];
    
    //now get info about his shares
    
    $portfolioRows = query("SELECT * FROM portfolios WHERE id = ?" , $userID);
    

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio" , "username" => $usersRow["username"] , 
           "balance" => $usersRow["cash"] , "portfolio" => $portfolioRows ]);
    
    
    

?>
