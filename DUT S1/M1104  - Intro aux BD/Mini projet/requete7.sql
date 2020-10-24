--Afficher les tables necessaires pour vérifier la requête

SELECT nom, budget
FROM equipe;

--7) Afficher la liste des équipe du + petit budget au + grand

SELECT nom, budget
FROM equipe
ORDER BY budget;