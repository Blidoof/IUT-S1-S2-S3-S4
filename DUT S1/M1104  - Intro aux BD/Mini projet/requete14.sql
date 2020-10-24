

-- affichage des tables nécessaires pour vérifier la validité de la requête

SELECT nom, prenom, numJoueur
FROM joueur;

SELECT nom, numComp
FROM competition
WHERE nom = 'CoupeFrance' AND saison = 2017;

SELECT *
FROM gagnerJ;

-- Afficher le nom des joueurs n'ayant pas remporté la compétition 'Coupe de France' en 2017

SELECT nom, prenom
FROM joueur
WHERE numJoueur NOT IN (
	SELECT numJoueur 
	FROM gagnerJ 
	WHERE numComp = 4);
