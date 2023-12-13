<?php 
  $db = "webtech";
  $conn = mysqli_connect("localhost", "root", "", $db) or die(mysqli_connect_error($conn));
  $sql = "select * from users";
  $res = mysqli_query($conn, $sql);
?>
<!DOCTYPE html>
<html>
<head>
  <title>Example 1</title>
</head>
<body>
  <table border="1">
    <tr>
      <th>Name</th>
      <th>Email</th>
      <th>Phone</th>
    </tr>
    <?php while($row = mysqli_fetch_assoc($res)){ ?>
      <tr>
        <td><?php echo $row["name"]; ?></td>
        <td><?php echo $row["email"]; ?></td>
        <td><?php echo $row["phone"]; ?></td>
      </tr>
    <?php } ?>
  </table>

  <a href="example1.html">Add new user</a>
</body>
</html>