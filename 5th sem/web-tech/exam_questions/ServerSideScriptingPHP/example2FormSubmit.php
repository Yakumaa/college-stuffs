<?php 
$servername = 'localhost';
$username = 'root';
$password = "";
$dbname = 'webtech';
$tablename = 'example2';
$conn = mysqli_connect($servername, $username, $password, $dbname) or die(mysqli_connect_error($conn));

if($_SERVER['REQUEST_METHOD'] == "POST"){
  $firstName = $_POST['firstName'];
  $lastName = $_POST['lastName'];
  $address = $_POST['address'];

  $sql = "INSERT INTO $tablename (firstName, lastName, address) VALUES ('$firstName', '$lastName', '$address')";
  if(mysqli_query($conn, $sql)){
    echo "New record created successfully";
  }else{
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
  }

  include 'example2.html';
  mysqli_close($conn);
}
?>