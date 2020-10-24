ALTER TABLE Competition
ADD (saison NUMBER(4), numEquipe NUMBER(3), 
FOREIGN KEY (numEquipe) REFERENCES Equipe(numEquipe));