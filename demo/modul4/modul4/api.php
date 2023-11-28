<?php
include 'koneksi.php';

$sql = "SELECT * FROM monitoring ORDER BY id DESC LIMIT 5";
$result = $con->query($sql);

if ($result) {
    $data = array();
    while ($row = $result->fetch_assoc()) {
        $data[] = $row;
    }

    header('Content-Type: application/json');
    echo json_encode($data);
} else {
    echo "Error: " . $sql . "<br>" . $con->error;
}

$con->close();
