<?php

$id = $_GET['id'];
include "db.php";
$sql = "select * from web where id=$id";
$res = mysqli_query($conn, $sql);
$row = mysqli_fetch_assoc($res);
// print_r($row);

?>

<form method="post" action="update.php?id=<?php echo $id;?>">
    name<input type="text" name="name" value="<?php echo $row['name'];?>"><br>
    roll<input type="text" name="roll" value="<?php echo $row['roll'];?>"><br>
    email<input type="text" name="email" value="<?php echo $row['email'];?>"><br>
    phone<input type="text" name="phone" value="<?php echo $row['phone'];?>"><br>
    <input type="submit" value="Update"><br>
</form>