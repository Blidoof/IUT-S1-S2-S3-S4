-- Creation des tables

CREATE TABLE Livre (
titreLivre VARCHAR2(50) PRIMARY KEY,
annee NUMBER(4) CHECK (annee > 0),
editeur VARCHAR2 (50),
genre VARCHAR2(15) CHECK ( genre IN ('scientifique', 'littérature', 'roman', 'aventure' ) ),
chiffreAffaire NUMBER(7) CHECK ( chiffreAffaire >0 ));

CREATE TABLE Chapitre (
numChapitre NUMBER (3) PRIMARY KEY,
titreLivre VARCHAR2 (50),
titreChapitre VARCHAR2 (50),
nbPages NUMBER (3),
FOREIGN KEY (titreLivre) REFERENCES Livre (titreLivre));

CREATE TABLE Auteur (
nom VARCHAR2 (20) PRIMARY KEY,
prenom VARCHAR2 (20),
dateNaissance VARCHAR2 (8));

CREATE TABLE Redaction (
nomAuteur VARCHAR2 (20),
numChapitre NUMBER (3),
FOREIGN KEY (nomAuteur) REFERENCES Auteur (nom),
FOREIGN KEY (numChapitre) REFERENCES Chapitre (numChapitre),
PRIMARY KEY (nomAuteur, numChapitre));

-- 1) Afficher les titres des livres édités chez l'editeur Vulcain

SELECT titreLivre
FROM livre
WHERE editeur = 'Vulcain';

-- 2) Afficher les titres des livres scientifiques apparus entre 63 et 65

SELECT titreLivre
FROM livre
WHERE genre = 'scientifique' AND annee BETWEEN 1963 AND 1965;

-- 3) Afficher le(s) éduteyr(s) qui a ( ou ont) édité un livre dont un des chapitres contenait QBE

SELECT editeur
FROM livre
WHERE titreLivre = (
	SELECT titreLivre
	FROM Chapitre
	WHERE titreChapitre LIKE '%QBE%');

-- 4) Afficher les noms des auteurs qui ont contribué à un chapitre entre 50 et 70 pages

SELECT nom
FROM auteur
WHERE nom = (
	SELECT nom
	FROM Redaction
	WHERE numChapitre =(
		SELECT numChapitre
		FROM chapitre
		WHERE nbPages BETWEEN 50 AND 70));

-- 5) Afficher les noms des auteurs qui ont contribué à un livre paru quand ils avaient moins de 25 ans
