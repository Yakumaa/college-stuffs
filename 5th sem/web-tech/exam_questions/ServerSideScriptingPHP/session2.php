<!-- get php session variables in another page -->
<?php
  session_start();
?>

<!DOCTYPE html>
<html>
<head>
  <title>Session</title>
</head>

<body>
  <h1>Session</h1>

  <?php
    // get session variables
    echo "Name: " . $_SESSION["name"] . "<br>";
    echo "Email: " . $_SESSION["email"] . "<br>";
  ?>

</body>
</html>