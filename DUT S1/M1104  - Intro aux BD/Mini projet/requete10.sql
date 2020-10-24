
-- affichage des tables nécessaires pour vérifier la validité de la requête

SELECT nom, budget
FROM equipe;

-- Afficher l'equipe au budget le plus grand

SELECT nom, budget
FROM equipe
WHERE budget = (
	SELECT MAX(budget)
	FROM equipe );
