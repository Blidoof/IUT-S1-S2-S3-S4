--Afficher les tables necessaires pour vérifier la requête

SELECT SUM(nbSelection), numEquipe
FROM joueur
GROUP BY numEquipe;

--Afficher le nombre de selection des équipes dont la somme est supérieure à 20

SELECT equipe.nom, SUM(joueur.nbSelection)
FROM joueur join equipe ON equipe.numEquipe = joueur.numEquipe
GROUP BY equipe.nom
HAVING SUM(joueur.nbSelection) > 20;