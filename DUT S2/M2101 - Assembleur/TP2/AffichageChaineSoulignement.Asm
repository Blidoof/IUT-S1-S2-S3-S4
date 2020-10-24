.DATA
chaine DW "Lea Cecchi, je vous hais."

.CODE

LEA SP, STACK
	
	LD R0,0
	OUT R0,5 ;Pour effacer l'écran
	LEA R0,chaine ;adresse de la chaine
	LD R1,50 ;coord x
	LD R2,100 ;coord y
	CALL affichageChaine
	LD R2,105 ;Nouvelle coodonée Y pour afficher la ligne juste sous le texte
	IN R3,1 ; On récupère la coordonée x de la dernière lettre affichée
	OUT R1,1 ; coord x départ de la ligne
	OUT R2,2 ; coord y départ de la ligne
	OUT R3,3 ; coord x d'arrivée de la ligne
	OUT R2,4 ; coord y d'arrivée de la ligne
	LD R1,%11100010 ;Commande d'affichage (trait jaune)
	OUT R1,5 ;Affichage
	HLT

affichageChaine:

	LD R3,'.'
	OUT R1,1 ;Coordonée x de la chaine dans le port 1
	OUT R2,2 ;Coordonée y de la chaine dans le port 2

	; Comme les coordonées x et y sont automatiquement mises à jour on
	; ne les intègre pas dans la boucle

	boucle:
	CMP R3, [R0] ;Si le caractère pointé par R0 est '.', on sort
	BEQ finAffichage
	OUT [R0],3 ;Caractère de la chaine à afficher dans port 3
	LD R4, %11100111 ;Commande d'affichage (caractère jaune)
	OUT R4,5 ; affichage du caractère
	INC R0
	JMP boucle

	finAffichage:
	RET

.STACK 15