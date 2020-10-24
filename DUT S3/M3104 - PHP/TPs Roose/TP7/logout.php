<?php

//On démarre la session
session_start();

//Destuction variables sesssions
session_unset();

//Destruction session
session_destroy();

//On redirige le visiteur vers la page d'accueil
header ('location: accueil.html');


 ?>
