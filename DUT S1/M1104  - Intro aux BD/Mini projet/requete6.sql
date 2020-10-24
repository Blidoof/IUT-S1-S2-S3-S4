--Afficher les tables necessaires pour vérifier la requête

SELECT equipe.nom, AVG(joueur.nbSelection)
FROM joueur join equipe ON equipe.numEquipe = joueur.numEquipe
GROUP BY equipe.nom;

--Afficher les équipes dont la moyenne de selection est inférieure à 5

SELECT equipe.nom, AVG(joueur.nbSelection)
FROM joueur join equipe ON equipe.numEquipe = joueur.numEquipe
GROUP BY equipe.nom HAVING AVG(joueur.nbSelection) < 5;