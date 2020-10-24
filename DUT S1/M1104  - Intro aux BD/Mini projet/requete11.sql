
-- affichage des tables nécessaires pour vérifier la validité de la requête

SELECT nom, capaciteStade
FROM equipe;

-- Afficher les equipes a  la capacité du stade supérieure a la moyenne de tout les stades

SELECT nom, capaciteStade
FROM equipe
WHERE capaciteStade < (
		SELECT AVG(capaciteStade) 
		FROM equipe);
