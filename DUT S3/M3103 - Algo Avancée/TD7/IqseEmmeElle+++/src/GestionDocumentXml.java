
//Nécéssités
import java.io.FileOutputStream;
import java.io.IOException;
import org.jdom2.Attribute;
import org.jdom2.Document;
import org.jdom2.Element;
import org.jdom2.output.Format;
import org.jdom2.output.XMLOutputter;

import java.util.Map;
import java.util.List;

public class GestionDocumentXml {

	// creation de constantes pour gérer les noms des balises
	private final String NOM_BALISE_RACINE = "tournoi";
	private final String NOM_BALISE_JOUEUR = "joueur";
	private final String NOM_BALISE_JOUEURS = "joueurs";
	private final String NOM_ATTRIBUT_TITULAIRE = "titulaire";
	private final String NOM_BALISE_NOM = "nom";
	private final String NOM_BALISE_PRENOM = "prenom";
	private final String NOM_BALISE_NUMERO = "numero";
	private final String NOM_BALISE_POSTE = "poste";
	private final String NOM_BALISE_PALMARES = "palmares";
	private final String NOM_ATTRIBUT_VAINQUEUR = "annee";
	private final String NOM_BALISE_VAINQUEUR = "vainqueur";
	private final String NOM_BALISE_EQUIPES = "equipes";
	private final String NOM_BALISE_EQUIPE = "equipe";

	// attributs : le document et la racine
	private Document document;
	private Element racine;

	// Constructeur
	public GestionDocumentXml() {
		racine = new Element(NOM_BALISE_RACINE);
		document = new Document(racine);
	}

	private void ajouteJoueur(Joueur joueur, Element parentJoueur) {
		/*
		 * Permet d'ajouter un objet Joueur au document XML dans la liste des joueurs
		 * d'une equipe
		 */
		Element elementJoueur = new Element(NOM_BALISE_JOUEUR);
		parentJoueur.addContent(elementJoueur);
		Attribute attributeClasse = new Attribute(NOM_ATTRIBUT_TITULAIRE, Boolean.toString(joueur.isEstTitulaire()));
		elementJoueur.setAttribute(attributeClasse);
		Element elementNom = new Element(NOM_BALISE_NOM);
		elementNom.setText(joueur.getNom());
		elementJoueur.addContent(elementNom);
		Element elementPrenom = new Element(NOM_BALISE_PRENOM);
		elementPrenom.setText(joueur.getPrenom());
		elementJoueur.addContent(elementPrenom);
		Element elementPoste = new Element(NOM_BALISE_POSTE);
		elementPoste.setText(joueur.getPoste());
		elementJoueur.addContent(elementPoste);
		Element elementNumero = new Element(NOM_BALISE_NUMERO);
		elementNumero.setText(String.valueOf(joueur.getNumero()));
		elementJoueur.addContent(elementNumero);
	}

	private void ajouteEquipe(Equipe equipe, Element parentEquipe) {
		// Permet d'ajouter un objet Equipe au document XML dans la liste
		// des equipes

		// Ajout attributs de base (création balise, ajout nom, joueurs)

		// Création balise
		Element elementEquipe = new Element(NOM_BALISE_EQUIPE);
		parentEquipe.addContent(elementEquipe);

		// Nom
		Element elementNom = new Element(NOM_BALISE_NOM);
		elementNom.setText(equipe.getNom());
		elementEquipe.addContent(elementNom);

		// Joueurs
		Element elementJoueurs = new Element(NOM_BALISE_JOUEURS);
		elementEquipe.addContent(elementJoueurs);

		// Ajout des joueurs

		// Récupération de la liste des joueurs
		Joueur[] lesJoueurs = equipe.getJoueurs();

		// Récupération de la taille du tableau
		int tailleTab = equipe.getNbJoueurs();

		// ajout
		for (int i = 0; i < tailleTab; i++) {
			ajouteJoueur(lesJoueurs[i], elementJoueurs);
		}
	}

	public void ajouteTournoi(Tournoi tournoi) {
		// Permet d'ajouter les attributs d'un tournoi au document XML

		// Ajout attributs de base (création balise, ajout nom, joueurs)

		// Nom
		Element elementNom = new Element(NOM_BALISE_NOM);
		racine.addContent(elementNom);
		elementNom.setText(tournoi.getNom());

		// Equipes
		Element elementEquipes = new Element(NOM_BALISE_EQUIPES);
		racine.addContent(elementEquipes);

		// Récupération de la liste des équipes
		List<Equipe> listeEquipes = tournoi.getListeEquipes();

		// Ajout
		for (Equipe element : listeEquipes) {

			ajouteEquipe(element, elementEquipes);
		}

		// Palmares
		Element elementPalmares = new Element(NOM_BALISE_PALMARES);
		racine.addContent(elementPalmares);

		// Récupération de la liste des palamares de l'équipe puis ajout
		for (Map.Entry<String, String> mapEntry : tournoi.getPalmares().entrySet()) {

			// Récupération de l'année
			String laCle = (String) mapEntry.getKey();

			// Récupération du nom
			String leNom = (String) mapEntry.getValue();

			// Balise Vainqueur
			Element elementVainqueur = new Element(NOM_BALISE_VAINQUEUR);
			elementPalmares.addContent(elementVainqueur);

			// Attribut anne de Vainqueur, et texte
			Attribute attributeVainqueur = new Attribute(NOM_ATTRIBUT_VAINQUEUR, laCle);
			elementVainqueur.setAttribute(attributeVainqueur);
			elementVainqueur.setText(leNom);
		}
	}

	public void affiche() {
		try {
			XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());
			sortie.output(document, System.out);
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}

	public void enregistre(String nomFichier) {
		try {
			XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());
			sortie.output(document, new FileOutputStream(nomFichier));
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}

	public Document getDocument() {
		return document;
	}

	public void setDocument(Document document) {
		this.document = document;
	}

	public Element getRacine() {
		return racine;
	}

	public void setRacine(Element racine) {
		this.racine = racine;
	}
}
