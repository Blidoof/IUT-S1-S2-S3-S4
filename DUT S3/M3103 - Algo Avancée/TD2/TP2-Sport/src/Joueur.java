/**
 * Projet : Système Equipe sport
 * Objectif : simuler une équipe de foot
 * Classe : Joueur
 * @author Arthur Murillo
 */
public class Joueur {
	private int id;
	private String nom;
	private String prenom;
	private int numero;
	private String poste;
	private boolean estTitulaire;
	
	public Joueur(int id, String nom, String prenom, int numero, String poste, boolean estTitulaire ) {
		this.id = id;
		this.nom = nom;
		this.prenom = prenom;
		this.numero = numero;
		this.poste = poste;
		this.estTitulaire = estTitulaire;
	}
	
	public void afficherJoueur() {
		System.out.println("Joueur n° :" + numero + " " + "Nom :" + nom + " " + prenom + " " + "Poste :" + poste);
		System.out.println(estTitulaire ? "Titulaire" : "Remplacant");
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
		if (!(nom == "")) {
			this.nom = nom;
		}
	}

	public String getPrenom() {
		return prenom;
	}

	public void setPrenom(String prenom) {
		this.prenom = prenom;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		if (!(numero < 1)) {
			this.numero = numero;
		}

	}

	public String getPoste() {
		return poste;
	}

	public void setPoste(String poste) {
		if (!(nom == "")) {
			this.poste = poste;
		}

	}

	public boolean isEstTitulaire() {
		return estTitulaire;
	}

	public void setEstTitulaire(boolean estTitulaire) {
		this.estTitulaire = estTitulaire;
	}
	

}
