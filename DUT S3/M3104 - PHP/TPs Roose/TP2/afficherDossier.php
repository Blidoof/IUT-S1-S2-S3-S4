<HTML><BODY>
<?php

//Test de l'existence du paramètre. Si non, récupération du dossier principal
if ( !(isset($_GET['param']))) {
	$directory = ".";
}
//Si oui, récupération du paramètre
else {
	$directory = $_GET['param'];
		
		//ANALYSE : est ce que le clic à eu lieu sur ".." ?
		$chemin = explode("/", $directory);
		
		//Si oui, on enleve "/dossier/.." du chemin passé en paramètre pour revenir en arrière
		if ($chemin[count($chemin)-1] == "..") {
			
			$directory = ""; //On vide le chemin d'accès initial
			
			for ($i =0 ; $i <= count($chemin)-3 ; $i++) {
				
				//On rajoute le nouveau chemin d'accès
				$directory .= $chemin[$i];
				$directory .= "/";	
			}
		}
}

//Renvoie un tableau contenant la liste des élements (fichiers) contenus dans le dossier
$dossier = scandir ( $directory );

//Traitement du tableau des fichiers
for ($i=0; $i <= count($dossier) - 1 ; $i++) {
	
	//Décomposition des noms de fichiers, en séparant les mots entre lesquels est situé un point
	$chaine = explode('.', $dossier[$i]);
	
	//Si extension (dernier morceau de la chaine) == docx, doc, xlsx
	if ( $chaine[count($chaine)-1] == "docx" || $chaine[count($chaine)-1] == "doc" || $chaine[count($chaine)-1] == "xlsx" ) {
		
		//Balise Href pour afficher un lien vers le fichier
		echo "<a href=$directory/$dossier[$i]> $dossier[$i](doc office)</a> <br>";
	}
	//
	else if ( $chaine[count($chaine)-1] == "txt"  ) {
		echo "<a href=$directory/$dossier[$i]> $dossier[$i] (doc texte)</a> <br>";
	}
	else if ($chaine[count($chaine)-1] == "jpg" || $chaine[count($chaine)-1] == "png") {
		
		//Balise href pour le lien avec img src pour afficher image
		echo "<a href = $directory/$dossier[$i] > <img src='$directory/$dossier[$i]' height = 25% width=25% alt='une belle photo' /> </a><br>";
	}
	else if (is_dir("$directory/$dossier[$i]")) {
		
		//
		echo "<a href=afficherDossier.php?param=$directory/$dossier[$i]> $dossier[$i] </a> <br>";
	}
	else
		echo "<a href=$directory/$dossier[$i]> $dossier[$i]</a> <br>";
		//On affiche le reste normalement
}
?>

</BODY></HTML>