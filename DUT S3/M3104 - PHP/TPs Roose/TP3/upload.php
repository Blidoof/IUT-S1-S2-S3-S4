<HTML> <BODY>
<?php  

//Définition du repertoire d'upload
$uploads_dir = './upload/';


//Traitement des fichiers contenus dans $_FILES
foreach ($_FILES["photos"]["error"] as $key => $error) {
	
	//Si téléchargement OK
	if ($error == UPLOAD_ERR_OK) {
		
		//Récupération du nom
		$name = basename($_FILES["photos"]["name"][$key]);
		
		//taille max 2,5 MB
		if ($_FILES["photos"]["size"][$key] < 2621440) {
		
			//On décompose le nom de fichier
			$testType = explode('/', $_FILES["photos"]["type"][$key]);
			
			//Si type = image
			if ($testType[0] == 'image') {
				
				//Récupération du nom temporaire
				$tmp_name = $_FILES["photos"]["tmp_name"][$key];
			
				//Deplacement
				move_uploaded_file($tmp_name, "$uploads_dir".$_FILES["photos"]["name"][$key]);
			
				//Calcul de la taille de bits à KB
				$taille = round( $_FILES["photos"]["size"][$key] / 1024, 2);
				
				//Affichage message succès
				echo "Vous avez uploadé le fichier $name de taille $taille KBits <br> <br>";
			
			}
			else {
				//Affichage message echec mauvais type
				echo "Le fichier $name n'a pas été uploadé car ce n'est pas une image <br> <br>";
			}
		}
		else {
			//Affichage message echec mauvaise taille
			echo "Erreur, le fichier $name est trop gros ! <br> <br>";
		}
	}
	else {
		//Affichage message echec upload
		echo "Erreur lors du téléchargement du fichier !";
	}
}
?>
</HTML> </BODY>