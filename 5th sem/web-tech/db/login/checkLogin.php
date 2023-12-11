<?php
session_start();

$uname = $_POST['name'];
$pwd = sha1($_POST['pwd']);
$sql = "select username from login where
  username = '$uname' and password='$pwd'";

function check(){
  include "db.php";

  $sql = "select * from login where uname='$uname' and pwd='$pwd'";
  $res = mysqli_query($conn, $sql);

  if(mysqli_num_rows($res)>0){
      $_SESSION["uname"]=$uname;
      return true;
  }
  else{
      return false;
  }
}

?>