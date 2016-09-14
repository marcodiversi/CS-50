<?php

    /**
     * register-3.php
     *
     * Computer Science 50
     * David J. Malan
     *
     * Implements a registration form for Frosh IMs.  Reports registration 
     * via email.  Redirects user to froshims-3.php upon error.
     */

    // require PHPMailer
    require("libphp-phpmailer/class.phpmailer.php");

    // validate submission
    if (!empty($_POST["name"]) && !empty($_POST["comfort"]) && !empty($_POST["dorm"]))
    {
        // instantiate mailer
        $mail = new PHPMailer();
         
        // use SMTP
        $mail->IsSMTP();
        $mail->Host = "smtp.gmail.com";
        $mail->Password = "crimson50";
        $mail->Port = 587;
        $mail->SMTPAuth = true;
        $mail->SMTPSecure = "tls";
        $mail->Username = "jharvard@cs50.net";
          
        // set From:
        $mail->SetFrom("jharvard@cs50.net");
          
        // set To:
        $mail->AddAddress("jharvard@cs50.net");

        // set Subject:
        $mail->Subject = "registration";
             
        // set body
        $mail->Body = 
            "This person just registered:\n\n" .
            "Name: " . $_POST["name"] . "\n" .
            "Captain: " . $_POST["captain"] . "\n" .
            "Comfort: " . $_POST["comfort"] . "\n" .
            "Dorm: " . $_POST["dorm"];

        // send mail
        if ($mail->Send() == false)
        {
            print($mail->ErrInfo);
            exit;
        }
    }
    else
    {
        header("Location: froshims-3.php");
        exit;
    }
?>

<!DOCTYPE html>

<html>
    <head>
        <title>Frosh IMs</title>
    </head>
    <body>
        You are registered!  (Really.)
    </body>
</html>
