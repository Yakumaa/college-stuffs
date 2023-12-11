<?php
  include "db.php";
  $name = $_POST['fname'];
  $roll = $_POST['roll'];
  $email = $_POST['email'];
  $phone = $_POST['phone'];

  $sql = "INSERT INTO web(name, roll, email, phone) VALUES ('$name','$roll','$email','$phone')";

  $res = mysqli_query($conn, $sql);

  if($res){
    header("location:list.php?succ=true");
  }
  else{
    die("failed".mysqli_error($conn));
  }


?>