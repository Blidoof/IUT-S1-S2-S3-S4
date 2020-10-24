CREATE TABLE Participer (
numComp NUMBER (3),
numEquipe NUMBER (3),
resultat NUMBER (2),
FOREIGN KEY (numComp)
REFERENCES Competition (numComp),
FOREIGN KEY (numEquipe)
REFERENCES Equipe (numEquipe),
PRIMARY KEY (numComp, numEquipe)
);