<!-- create an associative array of size 7 and diplay the array in HTML table witth key and value -->

<?php
  $arr = array("Monday" => "1", "Tuesday" => "2", "Wednesday" => "3", "Thursday" => "4", "Friday" => "5", "Saturday" => "6", "Sunday" => "7");

  echo "<table border='1'>";
  echo "<tr><th>Day</th><th>Number</th></tr>";
  foreach($arr as $key => $value){
    echo "<tr><td>$key</td><td>$value</td></tr>";
  }
  echo "</table>";
?>
