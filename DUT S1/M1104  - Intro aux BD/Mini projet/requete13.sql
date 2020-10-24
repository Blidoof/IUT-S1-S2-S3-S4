
-- affichage des tables nécessaires pour vérifier la validité de la requête
SELECT nom, numequipe
FROM equipe;

SELECT nom, saison, numequipe
FROM competition; 


-- Palmares (nom de la competition gagnee et saison) de l'equipe 'Madrid' :

SELECT  nom, saison
FROM competition 
WHERE numEquipe = (
	SELECT numEquipe
	FROM equipe
	WHERE equipe.nom = 'Madrid');
