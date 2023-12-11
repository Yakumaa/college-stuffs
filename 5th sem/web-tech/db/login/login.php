<?php

    if(isset($_GET['login'])){
        echo "Registration Successful! Please Login";
    }
    if(isset($_GET['logout'])){
        echo "you are logged out!";
    }

?>
<form method="post" action="home.php">
    Username<input type="text" name="uname"><br>
    Password<input type="password" name="pwd"><br>
    <input type="submit" value="submit"><br>
</form>   