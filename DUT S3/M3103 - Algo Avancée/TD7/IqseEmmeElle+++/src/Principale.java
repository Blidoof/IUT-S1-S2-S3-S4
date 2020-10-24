public class Principale {
	public static void main(String[] args) {
		
		Tournoi tournoi = new Tournoi("Superbowl");
		
		Equipe equipe = new Equipe("Cardinals",1);
		tournoi.ajouteEquipe(equipe);
		
		Joueur joueur1 = new Joueur(1,"Lee", "Andy", 2, "P", true);
		Joueur joueur2 = new Joueur(2,"Fitzgerald", "Larry", 11, "WR", true);
		Joueur joueur3 = new Joueur(3,"Ford", "Rudy", 30, "DB", false);
		
		equipe.ajouterJoueur(joueur1);
		equipe.ajouterJoueur(joueur2);
		equipe.ajouterJoueur(joueur3);
		
		equipe = new Equipe("Eagles",2);
		tournoi.ajouteEquipe(equipe);
		
		joueur1 = new Joueur(4,"Foles", "Nick", 9, "QB", false);
		joueur2 = new Joueur(5,"Agholor", "Nelson", 13, "WR", true);
		joueur3 = new Joueur(6,"Jenkins", "Malcolm", 27, "SS", true);
		
		equipe.ajouterJoueur(joueur1);
		equipe.ajouterJoueur(joueur2);
		equipe.ajouterJoueur(joueur3);
		
		tournoi.inscrirePalmares("2018", equipe);
		
		equipe = new Equipe("Patriots",3);
		tournoi.ajouteEquipe(equipe);
		
		joueur1 = new Joueur(7,"Brady", "Tom", 12, "QB", true);
		joueur2 = new Joueur(8,"Hogan", "Chris", 15, "WR", true);
		joueur3 = new Joueur(9,"Gostkowski", "Stephen", 3, "K", true);
		
		equipe.ajouterJoueur(joueur1);
		equipe.ajouterJoueur(joueur2);
		equipe.ajouterJoueur(joueur3);
		
		tournoi.inscrirePalmares("2017", equipe);
		
		GestionDocumentXml documentXml = new GestionDocumentXml();
		documentXml.ajouteTournoi(tournoi);
		documentXml.affiche();
		documentXml.enregistre("Jean.xml");
	}
}