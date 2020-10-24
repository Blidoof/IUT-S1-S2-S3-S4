import manipXML.manipulateurXML;;


public class Main {

	public static void main(String[] args) {
		
		manipulateurXML man = new manipulateurXML("", true, "Resultat.xml");
		
		man.supprimerFils("nom", "Lejardinier");
		man.supprimerFils("nom", "Don Corleone");
		man.affiche();
		man.enregistre("ResultatFinal.xml");
		
		

	}

}
