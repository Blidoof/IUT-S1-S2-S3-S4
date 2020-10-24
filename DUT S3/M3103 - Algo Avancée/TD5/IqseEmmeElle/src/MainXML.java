import org.jdom2.*;
import manipXML.*;

public class MainXML {

	static manipulateurXML man = new manipulateurXML("personnes");

	public static void main(String[] args) {

		//1ere balise etudiant, classe P2
		Element etudiant = man.ajouterElement("etudiant", man.getRacine());
		man.ajouterAttribut("classe", "P2", etudiant);
			
			//Nom : Cyn0
			man.ajouterElementTexte("nom", "Cyn0", etudiant);
			
			//Prenoms
			Element prenoms = man.ajouterElement("prenoms", etudiant);
			
				//Prenom 1
				Element prenom = man.ajouterElementTexte("prenom", "Nicolas", prenoms);
				
				//Prenom 2
				prenom = man.ajouterElementTexte("prenom", "Laurent", prenoms);
		
		//2eme balise etudiant classe P1
		etudiant = man.ajouterElement("etudiant", man.getRacine());
		man.ajouterAttribut("classe", "P1", etudiant);
			
			//nom
			prenom = man.ajouterElementTexte("nom", "WonderWoman", etudiant);
			
		//3eme balise etudiant, classe P1
		etudiant = man.ajouterElement("etudiant", man.getRacine());
		man.ajouterAttribut("classe", "P1", etudiant);
		
			//Nom
			prenom = man.ajouterElementTexte("nom", "Don Corleone", etudiant);

		// On affiche le document XML
		man.affiche();

		// On créer le fichier Exercice2.xml dans lequel on enregistre le document XML
		man.enregistre("Exercice2.xml");

	}

}
