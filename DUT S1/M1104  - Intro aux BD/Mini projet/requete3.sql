--Afficher les tables necessaires pour vérifier la requête

SELECT nbSelection, numEquipe
FROM joueur
ORDER BY numEquipe;

--Afficher la moyenne de selections par équipe

SELECT equipe.nom, AVG(joueur.nbSelection)
FROM joueur join equipe ON equipe.numEquipe = joueur.numEquipe
GROUP BY equipe.nom;