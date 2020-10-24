--Afficher les tables necessaires pour vérifier la requête

SELECT nom, capaciteStade
FROM equipe;

--Nom de l'équipe au stade le plus petit

SELECT nom
FROM equipe
WHERE capaciteStade =(
	SELECT MIN(capaciteStade) 
	FROM equipe);

