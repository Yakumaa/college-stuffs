<?php
include "../db.php";
$imgName = $_FILES['photo']['name'];
$imgType = $_FILES['photo']['type'];
$imgSize = $_FILES['photo']['size'];
$newImgName = "IMG".time().".".substr($imgType, 6);
$folder = 'image/'.$newImgName;
if (file_exists($imgName)){
  die("file already exists");
}
if($imgType != 'image/jpeg' && $imgType!= 'image/png'){
  die("invalid image type");
}
else if($imgSize > 50000000){
  die("image size exceeds");
}
else if(move_uploaded_file($_FILES['photo']['tmp_name'], $folder)){
  // die("files uploaded");
  $uname = $_POST["name"];
  $email = $_POST["email"];
  $pwd = sha1($_POST["pwd"]);
  $DOB = $_POST["DOB"];
  $is_verify = 1;
  
  $sql="insert into login(username, email, password, dob, is_verify, photo) values 
  ('$uname', '$email','$pwd', '$DOB', '$is_verify', '$newImgName')";
  
  $res = mysqli_query($conn, $sql);
  
  if($res){
    header("location:login.php?msg=true");
  }
}
else{
    header("location:register.php?msg=true");
}
    
?>