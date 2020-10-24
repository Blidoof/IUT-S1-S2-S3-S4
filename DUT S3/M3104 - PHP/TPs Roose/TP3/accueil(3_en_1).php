<HTML> <BODY>
<form enctype="multipart/form-data" method="GET">
	
	<!-- Récupération du nombre de photos à saisir-->
    
	<label for="name">Entrez le nombre de photos à saisir : </label>
    <input type="number" name="nbphotos" id="nbphotos">
    <input type="submit" value="Ok !">

</form>

	<!-- Génération du formulaire en conséquence-->
	
<?php
	
	if (isset($_GET['nbphotos'])) {
		
		
		$nbPhotos = $_GET['nbphotos'];
	

		//Ouverture balise formulaire
		echo "<FORM ENCTYPE='multipart/form-data' METHOD='POST'>";

	
		echo "<input type=hidden name=nbphotos value=$nbPhotos>";

		//Affichage de la saisie des fichiers à uploader (autant que de nbPhotos)
		for ($i = 1 ; $i <= $nbPhotos ; $i++) {
			
			echo "<input type=file name=\"photos[]\" multiple> <br> <br>";
		
		}

		//Affichage bouton
		echo "<input type=submit value='Télécharger Photos'>";

		//Fermeture balise formulaire
		echo "</FORM>";
	
	}
	
?>

	<!-- Récupération et upload des photos-->

<?php  

	if (isset($_FILES["photos"])) {
		
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
	}
?>

</BODY> </HTML>