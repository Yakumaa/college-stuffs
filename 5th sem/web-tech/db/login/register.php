<?php

    if(isset($_GET['msg'])){
        echo "error";
    }

?>

<form method="post" action="saveuser.php" enctype="multipart/form-data">
    username<input type="text" name="name"><br>
    email<input type="text" name="email"><br>
    password<input type="password" name="pwd"><br>
    Photo<input type="file" name="photo"><br>
    DOB<input type="date" name="DOB"><br>
    <input type="submit" value="Register"><br>

</form>    