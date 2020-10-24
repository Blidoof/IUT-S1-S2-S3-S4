<HTML> <BODY>
<?php
//Ouverture du fichier config
$file = fopen("./config.ini","r");

//Mise en place du formulaire
echo "<form enctype=\"multipart/form-data\" action=\"http://localhost/generation.php\" method=\"POST\">";

echo "<h1>Informations récupérées :</h1>";
echo "<h4>Un formulaire avec les champs suivants sera généré, <br> ainsi qu'un fichier php capable de le gérer.</h4>";

//Lecture du fichier
while (!feof($file)) {

	// Pour recupérer le contenu de la ligne sans caractères supplémentaires
	$line = chop(fgets($file));

	if ($line == '[NB]') {

		//Récupération du nombre de champs
		$taille = chop(fgets($file));
	}

	if ($line == '[NOMS]') {

		//On utilise un tableau HTML pour afficher proprement la saisie
		echo "<table>";

		for ($i = 1 ; $i <= $taille; $i++) {

			//On récupère la nouvelle ligne
			$champ = chop(fgets($file));

			//On prepare un nouvelle ligne dans le tableau
			echo "<tr>";

			//On ajoute dans la premiere colone le nom du champ à saisir
			echo "<td>".$champ." </td>";

			//On ajoute dans la deuxième colone le champ de saisie
			echo "<td><input type=hidden id=$champ name=$champ></td>";

			echo "</tr>";
		}
		echo "</table>";
	}
}

//Bouton
echo"<br> <input type=\"submit\" value=\"Générer !\">";

echo "</form>";
?>
</BODY></HTML>
