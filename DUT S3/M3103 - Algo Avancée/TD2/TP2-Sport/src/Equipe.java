
/**
 * Projet : Système Equipe sport
 * Objectif : simuler une équipe de foot
 * Classe : Equipe
 * @author Arthur Murillo
 */
public class Equipe {
	private final int NB_JOUEURS_MAX = 10;
	private int id;
	private String nom;
	private int nbJoueurs;
	private Joueur[] joueurs;
	
	public Equipe (String nom, int id) {
		this.id = id;
		this.nom = nom;
		nbJoueurs = 0;
		joueurs = new Joueur[NB_JOUEURS_MAX];
	}
	
	public void ajouterJoueur (Joueur joueur) {
		if (nbJoueurs < NB_JOUEURS_MAX) {
			this.joueurs[nbJoueurs] = joueur;
			nbJoueurs++;
			System.out.println ("Joueur ajouté");
		}
		else {
			System.out.println ("Equipe complète");
		}
	}
	
	public void afficherCompoEquipe () {
		System.out.println("Equipe : " + nom + " " + "Composition :");
		
		for (int i = 0 ; i < nbJoueurs ; i++) {
			System.out.println(joueurs[i].getNom() + " " + joueurs[i].getPrenom());
		}
	}
	
	public void afficherTitulairesOuRemplacants (boolean afficherTitulaires) {
		if (afficherTitulaires) {
			for (int i = 0 ; i < nbJoueurs ; i++) {
				if (joueurs[i].isEstTitulaire()) {
					System.out.println(joueurs[i].getNom() + " " + joueurs[i].getPrenom());
				}
			}
		}
		else {
			for (int i = 0 ; i < nbJoueurs ; i++) {
				if (!(joueurs[i].isEstTitulaire())) {
					System.out.println(joueurs[i].getNom() + " " + joueurs[i].getPrenom());
				}
			}
		}
	}
	
	public void supprimerJoueur (int numeroJoueur) {
		int caseASupprimer = 0;
		// On cherche la case a supprimer qui correspond au numéro (de maillot) du joueur que l'on veut supprimer
			while ( joueurs[caseASupprimer].getNumero() != numeroJoueur) {
				caseASupprimer++;
			}
			
			for (int i = caseASupprimer ; i < nbJoueurs-1 ; i ++) {
				joueurs[i].setNom(joueurs[i+1].getNom());		
				joueurs[i].setPrenom(joueurs[i+1].getPrenom());
				joueurs[i].setNumero(joueurs[i+1].getNumero());		
				joueurs[i].setPoste(joueurs[i+1].getPoste());
				joueurs[i].setId(joueurs[i+1].getId());		
				joueurs[i].setEstTitulaire(joueurs[i+1].isEstTitulaire());
			}
			System.out.println("Joueur supprimé avec succès");
			nbJoueurs--;
		
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getNbJoueurs() {
		return nbJoueurs;
	}

	public void setNbJoueurs(int nbJoueurs) {
		this.nbJoueurs = nbJoueurs;
	}

	public Joueur[] getJoueurs() {
		return joueurs;
	}

	public void setJoueurs(Joueur[] joueurs) {
		if (joueurs.length == NB_JOUEURS_MAX) {
			this.joueurs = joueurs;
		}
	}

	public int getNB_JOUEURS_MAX() {
		return NB_JOUEURS_MAX;
	}
	
	

}
