
public class MainSport {

	public static void main(String[] args) {
		Joueur a = new Joueur (1, "De la fontaine", "Jean", 23, "Gardien", true);
		Joueur b = new Joueur (2, "Etchebest", "Marie", 11, "Attaquant", false);
		Equipe equipe = new Equipe ("Liverpool", 3);
		
		equipe.ajouterJoueur(a);
		equipe.ajouterJoueur(b);
		equipe.afficherCompoEquipe();
		equipe.supprimerJoueur(11);
		equipe.afficherCompoEquipe();

	}

}
