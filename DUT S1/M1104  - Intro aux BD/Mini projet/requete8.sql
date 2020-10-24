--Afficher les tables necessaires pour vérifier la requête

SELECT nom, numJoueur
FROM joueur;

SELECT nom, numComp, saison
FROM competition
WHERE nom='CoupeFrance';

SELECT *
FROM gagnerJ
WHERE numComp = 1 OR numComp = 4 OR numComp = 7;

--8) Afficher la liste des joueurs (nom, prenom) ayant gagné la coupe de France (toutes saisons confondues) dans l'ordre ante-alphabétique

SELECT joueur.nom, joueur.prenom
FROM joueur JOIN gagnerJ ON gagnerJ.numJoueur = joueur.numJoueur 
JOIN competition ON competition.numComp = gagnerJ.numComp
WHERE competition.nom = 'CoupeFrance'
ORDER BY joueur.nom DESC;