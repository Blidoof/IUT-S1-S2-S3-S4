<?php

if (isset($_GET["param"])) {
	if ($_GET["param"]==1) {
		$ville="Tokyo";
	}
	if ($_GET["param"]==2) {
		$ville="Paris";
	}
	if ($_GET["param"]==3) {
		$ville="NY";
	}
}
else {
	die("Erreur : pas de paramètre passé");
}
header ('Content-Type: image/jpeg');
//Mise en place du header

$server = "localhost";//Le serveur
$username = "arthur"; //Login
$password = "arthur"; //Mdp
$db = "arthur"; //Le nom de la base de données

// Créer la connection
$conn = mysqli_connect($server, $username, $password,$db);

//Les requetes à utiliser
$NY = "SELECT indice FROM bourse WHERE ville='NY'";
$Paris = "SELECT indice FROM bourse WHERE ville='Paris'";
$Tokyo = "SELECT indice FROM bourse WHERE ville='Tokyo'";

//Soumettre la requête sql et récupérer le résultat dans résultat (1 par ville)
$resultatT = $conn->query($Tokyo);
$resultatN = $conn->query($NY);
$resultatP = $conn->query($Paris);


//Création de l'image vierge
$hauteur = 500;
$largeur = 500;
$image = imagecreate($hauteur, $largeur);

//Préparation des différentes couleurs 
$rouge = imagecolorallocate($image, 255, 0, 0); //Couleur fond
$blanc = imageColorAllocate($image, 255,255, 255); //Couleur texte
$bleu = imageColorAllocate($image, 0, 0, 255); //Couleur Paris
$vert = imageColorAllocate($image, 0, 255, 0); //Couleur NY
$jaune = imageColorAllocate($image, 255, 255, 0); //Couleur tokyo

//Initialisation du dessin de l'histograme
$x_start = 10;
$y_base = $hauteur;
$epaisseur_traits = 20;
$font = "C:\Windows\Fonts\arial.ttf";
$espacement_y_texte = 15;
$espacement_x_texte = 5;
$espacement_barres = 5;
$coef_agrandissement_indices = 10;
$taille_texte = 12;
$inclinaison_texte = 90;



// affichage pour new york

if ($ville == "NY") {
	
	while($row = $resultatN->fetch_assoc()) {
		
			//preparation de l'affichage
			$x_courant = $x_start + $epaisseur_traits;
			$chaine = "New York - ". $row["indice"];
			$hauteur_barre = $hauteur - ($row["indice"] * $coef_agrandissement_indices);
			$y_texte = $hauteur_barre - $espacement_y_texte;
			$x_texte = $x_courant - $espacement_x_texte;
			
			//affichage
			imagefilledrectangle($image, $x_start, $y_base, $x_courant, $hauteur_barre, $vert);
			imagettftext($image, $taille_texte, $inclinaison_texte, $x_texte, $y_texte, $blanc, $font, $chaine);
			//Preparation de la barre suivante
			$x_start = $x_courant + $espacement_barres;
	}
}
// affichage pour Paris

if ($ville == "Paris") {
	
	while($row = $resultatP->fetch_assoc()) {
		
			//preparation de l'affichage
			$x_courant = $x_start + $epaisseur_traits;
			$chaine = "Paris - ". $row["indice"];
			$hauteur_barre = $hauteur - ($row["indice"] * $coef_agrandissement_indices);
			$y_texte = $hauteur_barre - $espacement_y_texte;
			$x_texte = $x_courant - $espacement_x_texte;
			
			//affichage
			imagefilledrectangle($image, $x_start, $y_base, $x_courant, $hauteur_barre, $bleu);
			imagettftext($image, $taille_texte, $inclinaison_texte, $x_texte, $y_texte, $blanc, $font, $chaine);
			
			//Preparation de la barre suivante
			$x_start = $x_courant + $espacement_barres;
	}

}

// affichage pour Tokyo

if ($ville =="Tokyo") {

	while($row = $resultatT->fetch_assoc()) {
		
			//preparation de l'affichage
			$x_courant = $x_start + $epaisseur_traits;
			$chaine = "Tokyo - ". $row["indice"];
			$hauteur_barre = $hauteur - ($row["indice"] * $coef_agrandissement_indices);
			$y_texte = $hauteur_barre - $espacement_y_texte;
			$x_texte = $x_courant - $espacement_x_texte;
			
			//affichage
			imagefilledrectangle($image, $x_start, $y_base, $x_courant, $hauteur_barre, $jaune);
			imagettftext($image, $taille_texte, $inclinaison_texte, $x_texte, $y_texte, $blanc, $font, $chaine);
			
			//Preparation de la barre suivante
			$x_start = $x_courant + $espacement_barres;
	}
}

imagejpeg($image); //Generation de l'image

imagedestroy($image); //Liberation de la mémoire

mysqli_close($conn);

?>