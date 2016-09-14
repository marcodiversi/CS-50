<?php

    /**
     * register-1.php
     *
     * David J. Malan
     * malan@harvard.edu
     *
     * Implements a registration form for Frosh IMs.  Redirects 
     * user to froshims-1.php upon error.
     */

    // validate submission
    if (empty($_POST["name"]) || empty($_POST["comfort"]) || empty($_POST["dorm"]))
    {
        header("Location: froshims-1.php");
        exit;
    }

?>

<!DOCTYPE html>

<html>
    <head>
        <title>Frosh IMs</title>
    </head>
    <body>
        You are registered!  (Well, not really.)
    </body>
</html>
