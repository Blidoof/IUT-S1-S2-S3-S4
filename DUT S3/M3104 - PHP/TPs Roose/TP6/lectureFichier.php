<HTML> <BODY>
<?php

	//Chement du fichier xml
	$xml = new DOMDocument();
	$xml->load("fichier.xml");


	//Afficher tout les elements en les récupérant sans distinctions
	echo "<h1>Liste de tout les pays </h1>";

	echo $xml->saveXML();


	//Récupréation des valeurs appartenant au noeud "europe"
	$elements = $xml->getElementsByTagName('europe');

	//Affichage
	echo "<h1>Liste de tout les pays européens </h1>";

	foreach($elements as $element) {
		echo $element->nodeValue;
	}
?>

<br><br>
<h1> Rechercher un pays</h1>
<form class="formulaire" action="lectureFichier.php" method="post">
	<input type="text" name="pays">
	<input type="submit" name="laValidation" value="Ok">
</form>

<?php

	if (isset($_POST['pays'])) {
		$xml=simplexml_load_file("fichier.xml");

		echo "<h3> Pays d'Europe correspondant partiellement ou totalement:</h3>";
		foreach ($xml->europe->pays as $key => $pays) {
			//Expression régulière pour tester la présence de la chaine écrite
			if (preg_match("/^$_POST[pays]/", $pays) == 1){
				echo "- ". $pays . "<br><br>";
			}
		}

		echo "<h3> Pays d'Asie correspondant partiellement ou totalement:</h3>";
		foreach ($xml->asie->pays as $key => $pays) {
			//Expression régulière pour tester la présence de la chaine écrite
			if (preg_match("/^$_POST[pays]/", $pays) == 1){
				echo "- ". $pays . "<br><br>";
			}
		}
	}

 ?>
</BODY></HTML>
