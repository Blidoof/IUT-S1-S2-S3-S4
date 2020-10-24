CREATE TABLE GagnerJ (
numJoueur NUMBER(3),
numComp NUMBER(3),
PRIMARY KEY (numJoueur,numComp),
FOREIGN KEY (numComp)
REFERENCES Competition (numComp),
FOREIGN KEY (numJoueur)
REFERENCES Joueur (numJoueur)
);