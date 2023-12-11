<?php
$id = $_GET['id'];
$name = $_POST['name'];
$roll = $_POST['roll'];
$email = $_POST['email'];
$phone = $_POST['phone'];
include "db.php";
$sql = "update web set name='$name', roll='$roll', email='$email', phone='$phone' where id=$id";
$res = mysqli_query($conn, $sql);
if($res){
    header("location:list.php?update=success");
}
else{
    echo "error";
}