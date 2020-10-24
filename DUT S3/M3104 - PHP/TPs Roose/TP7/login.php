<?php

//On définit un login et un mot de passe valide

$login_valide = "moi";
$pwd_valide = "moi";

//On teste si les variables sont définies
if (isset($_POST['login']) && isset($_POST['password'])) {
  //On vérifie les informations saisies
  if ($login_valide == $_POST['login'] && $pwd_valide == $_POST['password']) {
    session_start();
    //On enregistre les parametres de session
    $_SESSION['login'] = $_POST['login'];
    $_SESSION['password'] = $_POST['password'];

    //Redirection
    header('location: page_membre.php');
  }
  else {
    echo '<body onLoad="alert(\' Membre non reconnu...\')">';
    echo '<meta http-equiv="refresh" content="0;URL=accueil.html">';
  }
}
else {
  echo "Les variables du formulaires ne sont pas déclarées";
}




 ?>
