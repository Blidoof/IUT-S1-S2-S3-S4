-- TP4

--Afficher la liste des nationalités des joueurs

SELECT DISTINCT nationalite
FROM Joueur;

-- Afficher la liste des équipes ( nom, capacité, stade, budget ) equipe 1, 2 et 3

SELECT Equipe.nom,  Equipe.capaciteStade, Equipe.budget
FROM EQUIPE
WHERE nom='Soumoulou' OR nom='Madrid'  OR nom='Paris Saint-germain';

--Afficher la liste des joueurs ( noms, prenoms ) dont le nom finit par a
--ENONCE MODIFIE, UN SEUL NOM FINISSANT PAR A 

SELECT nom, prenom
FROM Joueur
WHERE nom LIKE '%a';


--Afficher le nombre de nationalités différentes

SELECT COUNT ( DISTINCT nationalite )
FROM Joueur;

--Afficher la liste des joueurs de l'équipe 1

SELECT Joueur.nom, Joueur.prenom
FROM Joueur JOIN Equipe ON Equipe.numEquipe = Joueur.numEquipe
WHERE Equipe.nom='Soumoulou';

--Afficher nombre de joueurs de l'équipe 1

SELECT COUNT(numJoueur)
FROM Joueur JOIN Equipe ON Equipe.numEquipe = Joueur.numEquipe
WHERE Equipe.nom='Soumoulou';

-- Afficher le total de selection en equipe nationale des joueurs de l'équipe 1
SELECT SUM (nbSelection)
FROM JOUEUR JOIN EQUIPE ON Joueur.numEquipe = Equipe.numEquipe
WHERE Equipe.nom='Soumoulou';

-- Afficher la liste des equipes ( nom ) participant à la competition 1

SELECT Equipe.nom
FROM EQUIPE JOIN PARTICIPER ON Equipe.numEquipe = Participer.numEquipe
JOIN COMPETITION ON Participer.numComp = Competition.numComp
WHERE Competition.nom = 'CoupeFrance' ;

--Afficher la liste des équipes dontle stade a une capacité comprise ebtre 10 000 et 15 000 places
-- ( ENONCE MODIFIE, PAS D'EQUIPES AVEC UNE CAPACITE STADE ENTRE 30 000 ET 40 000 )

SELECT nom, capaciteStade
FROM EQUIPE
WHERE capaciteStade BETWEEN 10000 AND 15000;

--Afficher capacité moyenne des stades

SELECT AVG(capaciteStade)
FROM Equipe;

--Afficher somme des budgets

SELECT SUM(budget)
FROM EQUIPE;