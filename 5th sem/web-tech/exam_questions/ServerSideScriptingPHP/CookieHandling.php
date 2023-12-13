<!-- creating and retrieving cookies -->
<?php
    $cookie_name = "user";
    $cookie_value = "John Doe";
    //86400 = 1 day
    setcookie($cookie_name, $cookie_value, time() + (86400 * 30), "/");
    if(!isset($_COOKIE[$cookie_name])) {
        echo "Cookie named '" . $cookie_name . "' is not set!";
    } else {
        echo "Cookie '" . $cookie_name . "' is set!<br>";
        echo "Value is: " . $_COOKIE[$cookie_name];
    }
?>

<!-- deleting cookies -->
<?php
    $cookie_name = "user";
    $cookie_value = "John Doe";
    //86400 = 1 day
    setcookie($cookie_name, $cookie_value, time() + (86400 * 30), "/");
    // set the expiration date to one hour ago
    setcookie($cookie_name, "", time() - 3600);
?>

<html>
<body>
<?php
    echo "Cookie '" . $cookie_name . "' is deleted.";
?>
</body>
</html>
