.DATA

valinit DW 6
Fact DSW 1

.CODE
LEA SP, STACK

	LD R0,1
	LD R1,2
boucle: CMP R1, valinit ;On compare le registre R1 avec la variable valinit
	BGTU r1sup ;Si R1 > valinit, on sort de la boucle
	MUL R0,R1
	ADD R1,1
	JMP boucle
r1sup:  ST R0, Fact
HLT

.STACK 10
