.DATA
codeCoul DW 7
coordX DW 100
coordY DW 100
largeur DW 30
hauteur DW 10

.CODE
LEA SP, STACK
	
	LD R0,0 ;on efface l'écran
	OUT R0,5
	PUSH codeCoul ;On ajoute les variables dans la pile
	PUSH coordX
	PUSH coordY
	PUSH largeur
	PUSH hauteur
	CALL rectangle ;appel procédure dessin
	HLT
	
	
rectangle:
	PUSH R0
	LD R0, [SP+2] ;hauteur dans port 4
	OUT R0,4
	LD R0, [SP+3];largeur dans port 3
	OUT R0,3
	LD R0, [SP+4];coordY dans port 2
	OUT R0,2
	LD R0, [SP+5];coordX dans port 1
	OUT R0,1
	LD R0, 5 ;On ajoute la commande graphique a effectuer (rectangle plein) dans R0
	SHL [SP+6] ;Décalage de 4 bits à gauche de codeCoul pour pouvoir l'ajouter a la commande graphique dans R0
	SHL [SP+6]
	SHL [SP+6]
	SHL [SP+6]
	ADD R0, [SP+6] ;On concatenne codeCoul a la commande graphique
	OUT R0, 5 ;Dessin du rectangle de couleur codeCoul, de hauteur hauteur, de largeur largeur, 
			  ;et dont le coin supérieur gauche a pour coordonées coordX,coordY
	PULL R0
	RET 5
	
	
	
.STACK 15