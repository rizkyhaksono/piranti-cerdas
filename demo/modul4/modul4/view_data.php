<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>View Sensor Data</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 20px;
    }

    table {
      width: 100%;
      border-collapse: collapse;
      margin-top: 20px;
    }

    th,
    td {
      border: 1px solid #ddd;
      padding: 8px;
      text-align: left;
    }

    th {
      background-color: #f2f2f2;
    }
  </style>
</head>

<body>
  <h2>Sensor Data</h2>

  <?php
  $servername = "localhost";
  $username = "root";
  $password = "";
  $dbname = "piranti";

  $conn = new mysqli($servername, $username, $password, $dbname);

  if ($conn->connect_error) {
    die("Koneksi ke database gagal: " . $conn->connect_error);
  }

  $sql = "SELECT * FROM monitoring";
  $result = $conn->query($sql);

  if ($result->num_rows > 0) {
    echo "<table>";
    echo "<tr><th>ID</th><th>Angka Sumbu Y</th><th>Angka Sumbu X</th><th>Kemiringan X</th><th>Kemiringan Y</th><th>Sensor Value</th><th>Timestamp</th></tr>";

    while ($row = $result->fetch_assoc()) {
      echo "<tr>";
      echo "<td>" . $row["id"] . "</td>";
      echo "<td>" . $row["angka_sumbuY"] . "</td>";
      echo "<td>" . $row["angka_sumbuX"] . "</td>";
      echo "<td>" . $row["kemiringanX"] . "</td>";
      echo "<td>" . $row["kemiringanY"] . "</td>";
      echo "<td>" . $row["sensor_value"] . "</td>";
      echo "<td>" . $row["timestamp"] . "</td>";
      echo "</tr>";
    }

    echo "</table>";
  } else {
    echo "Tidak ada data sensor.";
  }

  $conn->close();
  ?>

</body>

</html>