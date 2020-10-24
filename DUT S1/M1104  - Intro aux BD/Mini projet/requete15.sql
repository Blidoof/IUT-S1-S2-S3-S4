
-- affichage des tables nécessaires pour vérifier la validité de la requête

SELECT nom, numEquipe
FROM  equipe;

SELECT numEquipe, AVG(nbSelection)
FROM joueur
GROUP by numEquipe;

SELECT nom, numEquipe
FROM joueur
ORDER BY numEquipe;



-- Afficher les joueurs faisant partie d'une equipe dont la moyenne de selection est inferieure à 5


SELECT nom, prenom
FROM joueur
WHERE numEquipe IN (
	SELECT numEquipe
	FROM joueur GROUP BY numEquipe
	HAVING AVG(nbSelection) < 5);


