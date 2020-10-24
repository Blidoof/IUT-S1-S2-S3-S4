<HTML><BODY>
<?php

//Ouverture du fichier en mode Lecture/écriture
$Fichier = fopen("StockageCompteur.txt","r+");

//Récupération de la valeur
$compteur = fgets($Fichier,255);

//Affichage valeur
print $compteur;

//Augmentation valeur
$compteur = $compteur + 1;

//Retour au début du fichier
fseek($Fichier, 0);

//Ecriture
fputs($Fichier,$compteur);

//Fermeture
fclose($Fichier);


?>

</BODY></HTML>