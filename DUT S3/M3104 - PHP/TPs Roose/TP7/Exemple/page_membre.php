<?php

//demarrage session
session_start();

//récupération variables
if (isset($_SESSION['login']) && isset($_SESSION['password']) ) {
  //test pour voir si variables ok
  echo "<html>";
  echo "<head>";
  echo "<title>Page de notre section membre </title>";
  echo "</head>";
  echo "<body>";
  echo "Votre login est ".$_SESSION['login']. " et votre mot de passe est ".$_SESSION['password'];
  echo "<br/>";
  echo "<a href=\"./logout.php\"> Deconnection</a>";
}
else {
  echo "Les variables ne sont pas déclarées";
}



 ?>
