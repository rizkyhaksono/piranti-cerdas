<?php
// include 'connection.php';
include './dbconnect.php';

$apikey = $_GET['apikey'];

date_default_timezone_set('Asia/Jakarta');

if ($apikey === $key) {
  $angle_x = $_GET['angkax'];
  $angle_y = $_GET['angkay'];


  $timestamp = date("Y-m-d H:i:s");

  $sql = "INSERT INTO sensor_data (angle_x, angle_y, time) VALUES ('$angle_x', '$angle_y', '$timestamp')";

  if ($con->query($sql) === TRUE) {
    echo "Data berhasil dimasukkan";
  } else {
    echo "Error: " . $sql . "<br>" . $con->error;
  }
} else {
  echo "Parameter tidak valid.";
}

$con->close();
