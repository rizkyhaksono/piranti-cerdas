<?php
include 'koneksi.php';

$apikey = $_GET['apikey'];

date_default_timezone_set('Asia/Jakarta');

if ($apikey === $key) {
    $angka_sumbuY = $_GET['angkay'];
    $angka_sumbuX = $_GET['angkax'];
    $kemiringanX = $_GET['kemiringanx'];
    $kemiringanY = $_GET['kemiringany'];
    $sensor_value = $_GET['sensor'];

    $timestamp = date("Y-m-d H:i:s");

    $sql = "INSERT INTO monitoring (angka_sumbuY, angka_sumbuX, kemiringanX, kemiringanY, sensor_value, timestamp) VALUES ('$angka_sumbuY', '$angka_sumbuX', '$kemiringanX', '$kemiringanY', '$sensor_value', '$timestamp')";

    if ($con->query($sql) === TRUE) {
        echo "Data berhasil dimasukkan";
    } else {
        echo "Error: " . $sql . "<br>" . $con->error;
    }
} else {
    echo "Parameter tidak valid.";
}

$con->close();
