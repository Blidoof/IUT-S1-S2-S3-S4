<?php

$host = "localhost";
$user = "arthur";
$pass = "arthur";
$db = "arthur";

// Connexion à la BDD

$link = mysqli_connect($host,$user,$pass,$db);

// Requete
$query = "SELECT ville FROM bourse WHERE ville='".$_GET["ville"]."'";

$r_query = $link->query($query);

if(mysqli_num_rows($r_query) >= 1)
{
  echo "existe";
}
else
{
  echo "existe_pas";
}

?>
