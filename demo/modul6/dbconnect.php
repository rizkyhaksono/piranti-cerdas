<?php
$host = "localhost";
$username = "root";
$password = "root";
$port = 3307;
$database = "pirdas_modul6";

$key = "d7af46c2-a29e-4f00-aeef-4e7555d8b5de";

$con = new mysqli($host, $username, $password, $database, $port);

if ($con->connect_error) {
  die("Koneksi gagal: " . $con->connect_error);
} else {
  echo 'Connected';
}

$con->set_charset("utf8");
