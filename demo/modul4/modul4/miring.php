<?php

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "pirdas_modul4";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
  die("Koneksi ke database gagal: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $angka_sumbu = $_POST["angka_sumbu"];
  $kemiringan = $_POST["kemiringan"];

  $sql = "INSERT INTO tabel_sensor_gerak (angka_sumbu, kemiringan) VALUES ('$angka_sumbu', '$kemiringan')";

  if ($conn->query($sql) === TRUE) {
    echo "Data berhasil ditambahkan ke database";
  } else {
    echo "Error: " . $sql . "<br>" . $conn->error;
  }
} else {
  echo "Metode request tidak valid.";
}

$conn->close();
