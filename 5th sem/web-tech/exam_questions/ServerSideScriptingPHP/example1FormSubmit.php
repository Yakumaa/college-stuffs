<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "webtech";
$conn = mysqli_connect($servername, $username, $password, $dbname) or die(mysqli_connect_error($conn));

if($_SERVER["REQUEST_METHOD"] == "POST"){
  $name = $_POST["name"];
  $email = $_POST["email"];
  $phone = $_POST["phone"];

  $sql = "INSERT INTO users (name, email, phone) VALUES ('$name', '$email', '$phone')";
  if(mysqli_query($conn, $sql)){
    echo "New record created successfully";
    print'<script> window.location.assign("example1Display.php");</script>';
  }else{
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
  }

  mysqli_close($conn);
}

?>