.DATA

premier_clic DSW 1 ;Indiciteur de l'existence du premier clic pour le premier trait
x DSW 1 ;Coord x du point cliqué
y DSW 1 ;Coord y du point cliqué
ancien_x DSW 1 ;Coord x du point cliqué precedemment
ancien_y DSW 1 ;Coord y du point cliqué precedemment
couleur DSW 1 ;Couleur du dessin
largeur DW 20 ;Largeur des bandes de la zone choix couleur
hauteur DW 16 ;Hauteur des bandes de la zone choix couleur
nbBandes DW 0 ; compteur du nb de bandes dessinées dans zone choix couleur


.CODE
LEA SP, STACK
	
	;effacer l'écran
	LD R0,0
	OUT R0,5
	
	;afficher la palette de couleurs
	CALL paletteCouleur
	
	;premier_clic =0
	LD R0,0
	ST R0,premier_clic


boucle:

	boucleSouris:
		IN R0,0
		CMP R0,%11000111 ;Si clic a eu lieu on continue, sinon on teste a nouveau
		BEQ suite
		JMP boucleSouris
	
	suite:
		;Recuperation coord en X
		IN R0,6
		ST R0,x
	
		;Recuperation coord en Y
		IN R0,7
		ST R0,y
		
		LD R0,x
		CMP R0,20
		BGTU zoneDessin;Si x > 20 alors on est en zone couleur, sinon on est en zone choix dessin
		
		;Couleur prend y/16
		LD R0,y
		DIV R0,16
		ST R0,couleur
		JMP boucleSouris
		
		zoneDessin:
			LD R0,premier_clic
			CMP R0,0 ;Si premier_clic = 0, on change l'état , sinon on dessine
			BEQ changementEtatClic
			
			LD R0,ancien_x ;chargement coord X depart
			OUT R0,1
			
			LD R0,ancien_y ;chargement coord Y depart
			OUT R0,2
			
			LD R0,x ;chargement coord X arrivee
			OUT R0,3
			
			LD R0,y ;chargement coord Y arrivee
			OUT R0,4
	
			;On met la commande graphique (dessin trait) dans R0
			LD R0,2
			
			;On decale la couleur de 4 bits a gauche pour pouvoir l'additionner a la commande deja présente dans R0
			SHL couleur
			SHL couleur
			SHL couleur
			SHL couleur
			
			;on additionne R0 et la couleur puis on dessine
			ADD R0,couleur
			OUT R0,5
			
			;On redecale la couleur de 4 bits a droite pour pouvoir la modifier a nouveau
			SHR couleur
			SHR couleur
			SHR couleur
			SHR couleur
			
			;Maintenant que la ligne est tracée, on va preparer la ligne suivante
			JMP sauvegardeAnciennesCoord
			
			;On change l'état de premier clic
			changementEtatClic:
			LD R0,1
			ST R0,premier_clic
			
			sauvegardeAnciennesCoord:
			;x devient ancien x (on sauvegarde sa position precedente)
			LD R0,x
			ST R0,ancien_x
			
			;y devient ancien y (on sauvegarde sa position precedente)
			LD R0,y
			ST R0,ancien_y
			
			;Retour debut boucle pour attendre clic suivant
			JMP boucleSouris
			
			
paletteCouleur:

	LD R1, nbBandes
	
	boucleBandes:
	
		CMP R1, 16 ;Si nombre de bandes >= 17, on arrete de dessiner les bandes
		BGTU fin
		PUSH couleur ;On ajoute les variables necessaires au dessin dans la pile
		PUSH x
		PUSH y
		PUSH largeur
		PUSH hauteur
		CALL rectangle ;appel procédure dessin
	
		;Quand dessin terminé
		INC couleur ;On change de couleur
	
		LD R3, y ;On augmente la coordonée Y de 16 pixels
		ADD R3,16
		ST R3, y
	
		INC R1 ;On augmente le compteur du nombre de bandes déssinées
	
		JMP boucleBandes ;On recommence
	fin:
		RET

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
	SHL [SP+6] ;Décalage de 4 bits à gauche de couleur pour pouvoir l'ajouter a la commande graphique dans R0
	SHL [SP+6]
	SHL [SP+6]
	SHL [SP+6]
	ADD R0, [SP+6] ;On concatenne couleur a la commande graphique
	OUT R0, 5 ;Dessin du rectangle de couleur couleur, de hauteur hauteur, de largeur largeur, 
			  ;et dont le coin supérieur gauche a pour coordonées coordX,coordY
	PULL R0
	RET 5


.STACK 15