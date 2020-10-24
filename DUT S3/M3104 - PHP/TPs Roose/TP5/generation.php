<?php

//Chemin des fichiers
$ficHtml = "formulaires.html";
$ficPhp = "gestionFormulaires.php";

//Variables representant les fichiers
$HTML = fopen($ficHtml, "w");

//Génération du HTML
	//Mise en forme
	fputs($HTML, "<HTML><BODY>\n");
	fputs($HTML, "<form enctype=\"multipart/form-data\" action=\"http://localhost/$ficPhp\" method=\"POST\">\n");
	fputs($HTML, "<h1> Saisissez les valeurs </h1>\n");

	//Mise en place d'un tableau pour que les champs de saisie soient alignés
	fputs($HTML, "<table>\n");
	foreach(array_keys($_POST) as $champ) {
		//Nouvelle ligne
		fputs($HTML, "\t<tr>\n");
		//Ajout du nom du champ
		fputs($HTML, "\t\t<td> $champ : </td>\n");
		//Formulaire
		fputs($HTML, "\t\t<td><input type=\"text\" id=$champ name=$champ></td>\n");

		fputs($HTML, "\t</tr>\n");

	}
	fputs($HTML, "</table>\n\n");

	//Bouton de confirmation
	fputs($HTML, "<br> <input type=\"submit\" value=\"Confirmer !\">\n\n");


	fputs($HTML, "</form>\n");
	fputs($HTML, "</BODY></HTML>");

fclose($HTML);


//Génération du PHP
$PHP = fopen($ficPhp, "w");

	//Mise en forme
	fputs($PHP, "<HTML><BODY>\n");
	fputs($PHP, "<?php\n\n");

	//Titre
	fputs($PHP, "echo \"<h2> Vous avez saisi les valeurs :</h2><br>\";\n\n");


	//Affichage des éléments
	fputs($PHP, "foreach (\$_POST as \$valeur) {\n\n");

	fputs($PHP, "\t echo \"\$valeur <br><br>\"; \n\n");

	fputs($PHP, "}\n\n");

	fputs($PHP, "echo \"<h4 style=font-family:verdana> Merci d'avoir choisi PHP© Airlines</h4>\"\n\n");




	fputs($PHP, "?>\n");
	fputs($PHP, "</BODY></HTML>");
fclose($PHP);


?>
