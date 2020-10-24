--CREATION ET PEUPLEMENT DES TABLES

--Creation des tables étudiant, cours, moyenneNotation

CREATE TABLE Etudiant (
num INTEGER,
nom VARCHAR2(50) NOT NULL,
prenom VARCHAR2(50),
anniversaire VARCHAR2(10),
niveau VARCHAR2(2) CHECK ( niveau IN ( '1', '2', 'AS', 'LP')),
groupe NUMBER(1),
departement VARCHAR2(15),
PRIMARY KEY (num));

CREATE TABLE Cours (
num VARCHAR2(10),
intitule VARCHAR2(80),
PRIMARY KEY(num));

CREATE TABLE moyenneNotation (
moyenne NUMBER(4,2),
numEtud INTEGER,
numCours VARCHAR2(10),
FOREIGN KEY (numEtud) REFERENCES Etudiant (num),
FOREIGN KEY (numCours) REFERENCES Cours(num),
PRIMARY KEY (numEtud, numCours));

-- Peuplement de Etudiant

INSERT INTO Etudiant VALUES (
15, 'Dupont', 'Jacques', '10/11/1977', '2', 2, 'Informatique');

INSERT INTO Etudiant VALUES (
222, 'Dupre', 'Erneste', '15/02/1978', '2', 2, 'GMP');

INSERT INTO Etudiant VALUES (
345, 'La Folie', 'Pierre', '23/09/1979', '1', 3, 'Biologie');

INSERT INTO Etudiant VALUES (
346, 'Dupond', 'Claire', '23/10/1978', 'AS', 4, 'Informatique');

INSERT INTO Etudiant VALUES (
543, 'Durant', 'Pauline', '25/10/1978', 'LP', 4, 'Informatique');

INSERT INTO Etudiant VALUES (
955, 'Larue', 'Jean', '02/02/1976', '2', 1, 'Informatique');

INSERT INTO Etudiant VALUES (
956, 'Le poete', 'Jean', '03/10/1975', '1', 1, 'Informatique');

--Peuplement de Cours

INSERT INTO Cours VALUES (
'CX44', 'Mathématiques');

INSERT INTO Cours VALUES (
'CX56', 'Informatique');

INSERT INTO Cours VALUES (
'UZ34', 'Commerce international');

--Peuplement de MoyenneNotation

INSERT INTO moyenneNotation VALUES (
14.7, 15, 'CX44');

INSERT INTO moyenneNotation VALUES (
18.9, 222, 'UZ34');

INSERT INTO moyenneNotation VALUES (
7.5, 345, 'CX56');

INSERT INTO moyenneNotation VALUES (
10, 346, 'CX44');

INSERT INTO moyenneNotation VALUES (
16, 543, 'CX56');

INSERT INTO moyenneNotation VALUES (
7.3, 955, 'UZ34');

INSERT INTO moyenneNotation VALUES (
20, 955, 'CX44');




--REQUETES

--1) Etudiants de 1ere année dans l'ordre alphabétique

SELECT nom, prenom
FROM Etudiant 
WHERE niveau ='1'
ORDER BY nom;

--2) Nom de famille entre A et C

SELECT nom, prenom
FROM etudiant
WHERE nom BETWEEN 'A' and 'C';

--3) Etudiants dont le nom contient '..Du..'

SELECT nom, prenom
FROM etudiant
WHERE nom LIKE '%Du%';

--4) Etudiants nés entre 1977 et 1978

SELECT nom, prenom
FROM etudiant
WHERE anniversaire LIKE '%77' OR anniversaire LIKE '%78'
AND departement = 'Informatique';

--5)

--6) Etudiants pour lesquels la date d'anniversaire n'est pas renseignée

SELECT nom, prenom
FROM Etudiant
WHERE anniversaire= NULL;

--7)Nom des étudiants de 2e année qui ont la moyenne en mathématiques

SELECT nom, prenom
FROM Etudiant
WHERE niveau = '2' AND num = ( 
  SELECT numEtud
  FROM moyenneNotation
  WHERE moyenne >= 10
  AND numCours = 'CX56');

--8) Pour chaque matière, afficher note maximale, note minimale et note moyenne attribuée

SELECT numCours, MIN(moyenne), AVG(moyenne), MAX(moyenne)
FROM moyenneNotation
GROUP BY numCours;

--9) Afficher le classement des étudiants. Utiliser moyenne générale de chaque étudiants

SELECT nom, prenom, AVG(moyenne)
FROM Etudiant JOIN moyenneNotation on Etudiant.num = moyenneNotation.numEtud
GROUP BY nom, prenom
ORDER BY AVG(moyenne);

--10) Remplacer GMP par 'Génie mécanique et productique'

ALTER TABLE etudiant
MODIFY departement VARCHAR2(60);

UPDATE etudiant
SET departement = 'Génie Mécanique et Productique'
WHERE departement = 'GMP';

--11) Supprimer l'enregistrement de l'étudiant numéro 15

DELETE FROM moyenneNotation WHERE numEtud = 15;
DELETE FROM etudiant WHERE num = 15;




