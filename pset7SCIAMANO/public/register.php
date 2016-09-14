<?php
    
    //configuration
    require("../includes/config.php");

    //if user reached page via GET
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
    
       //else render form
       render("register_form.php", ["title" => "Register"]);
    
    }

    //else if user reached page via POST
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
      //user empty
      if (empty($_POST["username"]))
      {
          apologize("ERROR: The username field is empty");
      
      }
      
      //pass empty
      if (empty($_POST["password"]))
      {
           apologize("ERROR: The password field is empty");
      }
      
      //pass and confirmation pass do not match
      if ($_POST["password"] != $_POST["confirmation"])
      {
          apologize("ERROR: The passwords do not match");
      }
      
      //insert new user into the database
      
      $check = query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"],
             crypt($_POST["password"]));
      
      //check if insertion was successful
      if ($check === false)
      {
          apologize("ERROR: User already exists");
      }
      
      $rows = query("SELECT LAST_INSERT_ID() AS id");
      $id= $rows[0]["id"];
      
      $_SESSION["id"] = $id;
      redirect("index.php");
    
    }

?>
