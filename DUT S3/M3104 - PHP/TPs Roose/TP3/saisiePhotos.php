<HTML> <BODY>
<?php

//Récupération du nb de photos à uploader
$nbPhotos = $_POST['nbphotos'];

//Ouverture balise formulaire
echo "<FORM ENCTYPE='multipart/form-data' ACTION='upload.php' METHOD='POST'>";

//Permet de passer des variables "discretemen" à l'aide d'un input qui ne sera pas affiché
echo "<input type=hidden name=nbphotos value=$nbPhotos>";

//Affichage de la saisie des fichiers à uploader (autant que de nbPhotos)
for ($i = 1 ; $i <= $nbPhotos ; $i++) {
	echo "<input type=file name=\"photos[]\" multiple> <br> <br>";
}

//Affichage bouton
echo "<input type=submit value='Télécharger Photos'>";

//Fermeture balise formulaire
echo "</FORM>";

?>
</HTML> </BODY>
