--Afficher les tables necessaires pour vérifier la requête

SELECT numEquipe, COUNT(*)
FROM joueur
GROUP BY numEquipe;

--Afficher le nom des équipes ayant plus de 5 joueurs

SELECT equipe.nom, COUNT(*)
FROM joueur JOIN equipe ON joueur.numEquipe = equipe.numEquipe
GROUP BY equipe.nom
HAVING COUNT(*) > 5;