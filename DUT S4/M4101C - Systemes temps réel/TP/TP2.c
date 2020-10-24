#include "libTPIUT.h"
#include "robot.h"
#include "stdio.h"
#define PORT_BP1 PortB
#define PORT_BP2 PortC
#define PORT_DELD PortB
#define PORT_DELC PortA
#define PORT_DELG PortC
#define LIGNE_DELD 27
#define LIGNE_DELC 21
#define LIGNE_DELG 30
#define LIGNE_BP1 25
#define LIGNE_BP2 26
#define RESET 6
#define ANGLE_MOUVEMENT 1
#define LIMITE_MOUVEMENTS 30

void init();
void changerDiode(int moteur);
void allumerDiodes(int gauche, int milieu, int droite);

int main (void)
{
	initCarte();
	initRobot();
	configureConsole();
	init();
	int cycleSens = 0;
	int moteur = 0;
	int distanceParcourue = 0;
	int historiquePositions[5] = {0,0,0,0,0};
	int sens[4] = {ANGLE_MOUVEMENT, -ANGLE_MOUVEMENT, -ANGLE_MOUVEMENT, ANGLE_MOUVEMENT};
	int moteurs[6] = {BASE, EPAULE, COUDE, POIGNET, PINCE};
	while(true) {
		if (lireLigne(PORT_BP1, LIGNE_BP1) == 1) {
			//lancerTimer(Timer3);
			
			
			lancerTimer(Timer0);
			while(distanceParcourue <= LIMITE_MOUVEMENTS) {
				historiquePositions[moteur] += sens[cycleSens];
				positionnerMoteur(moteurs[moteur], historiquePositions[moteur]);
				distanceParcourue++;
				while(!testerEtatTimer(Timer0, LIMITE)) {}
			}
			arreterTimer(Timer0);
			distanceParcourue = 0;
			cycleSens =(cycleSens+1)%4;
			while(lireLigne(PORT_BP1, LIGNE_BP1) == 1);
		}
		if (lireLigne(PORT_BP2,LIGNE_BP2) == 1)
		{
			moteur = (moteur+1)%5;
			changerDiode(moteur);	
			while(lireLigne(PORT_BP2,LIGNE_BP2) == 1);
		}
	}
}



void changerDiode(int moteur) {
	switch(moteur) {
		case BASE: 
			allumerDiodes(1,1,1); //Droite allumée quand base
			break;
		case EPAULE: 
			allumerDiodes(1,0,0); //milieu allumée quand epaule
			break;
		case COUDE: 
			allumerDiodes(1,0,1); //Droite et milieu allumée quand coude
			break;
		case POIGNET: 
			allumerDiodes(0,1,0); //gauche allumée quand poignet
			break;
		case PINCE: 
			allumerDiodes(0,1,1); //gauche allumée quand pince
			break;
	}
}

void allumerDiodes(int gauche, int milieu, int droite) {
	ecrireLigne(PORT_DELG, LIGNE_DELG, gauche);
	ecrireLigne(PORT_DELC, LIGNE_DELC, milieu);
	ecrireLigne(PORT_DELD, LIGNE_DELD, droite);
}

void init() {
	allumerPeriph(PORT_BP1);
	allumerPeriph(PORT_BP2);
	allumerPeriph(PORT_DELC);
	allumerPeriph(Timer0);
	allumerPeriph(Timer3);
	timerModeDelai(Timer0, HDIV2, 1680000UL , REPETITIF, INC);
	timerModeMesure(Timer3, HDIV2, 84000000UL, DE_0_A_1);
	programmerLigne(PORT_BP1, LIGNE_BP1, ENTREE);
	programmerLigne(PORT_BP2, LIGNE_BP2, ENTREE);
	programmerLigne(PORT_DELC, LIGNE_DELC, SORTIE1 );
	programmerLigne(PORT_DELD, LIGNE_DELD, SORTIE1);
	programmerLigne(PORT_DELG, LIGNE_DELG, SORTIE1);
	activerFiltrageLigne(PORT_BP1, LIGNE_BP1, 20);
	activerFiltrageLigne(PORT_BP2, LIGNE_BP2, 20);
}