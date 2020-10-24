
-- affichage des tables nécessaires pour vérifier la validité de la requête

SELECT nom, prenom, nbSelection
FROM joueur;

-- Afficher la liste des joueurs, et leur nombre de selection, de l'equipe Soumoulou

SELECT nom, prenom, nbSelection
FROM Joueur
WHERE numEquipe = (
	SELECT numEquipe
	FROM Equipe
	WHERE nom ='Soumoulou');
