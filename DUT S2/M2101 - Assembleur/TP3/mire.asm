.DATA
codeCoul DW 0
coordX DW 0
coordY DW 0
largeur DW 255
hauteur DW 16
nbBandes DW 0 ; compteur du nb de bandes déssinées

.CODE
LEA SP, STACK
	
	LD R1, nbBandes 
	
	LD R0,0 
	OUT R0,5 ;on efface l'écran
	
boucle:
	CMP R1, 16 ;Si nombre de bandes >= 17, on arrete de dessiner
	BGTU fin
	PUSH codeCoul ;On ajoute les variables necessaires au dessin dans la pile
	PUSH coordX
	PUSH coordY
	PUSH largeur
	PUSH hauteur
	CALL rectangle ;appel procédure dessin
	
	;Quand dessin terminé
	INC codeCoul ;On change de couleur
	
	LD R3, coordY ;On augmente la coordonée Y de 16 pixels
	ADD R3,16
	ST R3, coordY
	
	INC R1 ;On augmente le compteur du nombre de bandes déssinées
	
	JMP boucle ;On recommence
fin:
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