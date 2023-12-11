<?php
  include "db.php";
  $id = $_GET["id"];

  $sql = "delete from web where id=$id";
  $res = mysqli_query($conn, $sql);

  if($res){
    header("location:list.php?del=true");
  }
  else{
    die("operation failed.mysqli_error");
  }

?>