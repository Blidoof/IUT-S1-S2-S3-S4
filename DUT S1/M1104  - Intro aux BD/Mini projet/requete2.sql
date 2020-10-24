--Afficher les tables necessaires pour vérifier la requête

SELECT joueur.nom, equipe.numEquipe
FROM equipe JOIN joueur ON equipe.numEquipe = joueur.numEquipe
ORDER BY equipe.numEquipe;

--Afficher le nombre de joueurs par équipe

SELECT numEquipe, COUNT(*)
FROM joueur
GROUP BY numEquipe;