<?php
header("Access-Control-Allow-Origin: *");

$host = "localhost";
$user = "arthur";
$pass = "arthur";
$db = "arthur";

// Connexion à la BDD
$link = mysqli_connect($host,$user,$pass,$db);

$query = 'SELECT quote FROM THANOS ORDER BY RAND() LIMIT 1';

$r_query = $link->query($query);

header('Content-Type: application/json');
while ($row = $r_query->fetch_assoc()) {
  $tab = array("message" => chop($row["quote"]). " " .$_GET["fin"]);
  echo json_encode($tab);
}

mysqli_close($link);

?>
