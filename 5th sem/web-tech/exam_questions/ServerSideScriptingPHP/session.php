<!-- start a session -->
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
    // set session variables
    $_SESSION["name"] = "John Doe";
    $_SESSION["email"] = "thisis@email";
  
    echo "Session variables are set.";
  ?>

</body>
</html>

