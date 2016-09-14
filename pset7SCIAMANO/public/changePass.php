<?php

        //configuration
    require("../includes/config.php");
    
    //get user info
    $userID = $_SESSION["id"];
    $userRows = query("SELECT * FROM users WHERE id = ?" , $userID);
    $userInfo = $userRows[0];

    //if user reached page via GET
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
    
        //else render form
        render("changePass_form.php", ["title" => "Change Password"]);
    
    }
    
    //else if user reached page via POST
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    
    //user empty
      if (empty($_POST["oldPass"]))
      {
          apologize("ERROR: The Old Password field is empty");
      
      }
      
      //pass empty
      if (empty($_POST["newPass"]))
      {
           apologize("ERROR: The New Password field is empty");
      }
      
      //confirm pass empty
      if (empty($_POST["confirmPass"]))
      {
           apologize("ERROR: The Confirm-password field is empty");
      }
      
      //pass and confirmation pass do not match
      if ($_POST["newPass"] != $_POST["confirmPass"])
      {
          apologize("ERROR: The passwords do not match");
      }
      
      //update the password hash in the database

           
       if ((crypt($_POST["oldPass"], $userInfo["hash"])  == $userInfo["hash"]) == 1)
       {
          query("UPDATE users SET hash = ? WHERE id = ?" , crypt($_POST["newPass"]), $userID);
          render("changePass_success.php" , ["title" => "Password Change Success"]);     
       }
       
       if ((crypt($_POST["oldPass"], $userInfo["hash"])  == $userInfo["hash"]) != 1)
       {
            apologize("ERROR: The old password does not match with you input");
       }

}




?>
