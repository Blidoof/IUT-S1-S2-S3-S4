CREATE TABLE Joueur (
numJoueur NUMBER (3) PRIMARY KEY,
nom VARCHAR2 (20),
prenom VARCHAR2 (20),
nationalite VARCHAR2 (20),
nbSelection NUMBER (3),
numEquipe NUMBER (3),
FOREIGN KEY (numEquipe)
REFERENCES Equipe (numEquipe)
);