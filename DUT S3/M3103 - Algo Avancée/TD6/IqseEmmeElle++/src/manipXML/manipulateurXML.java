/*
* Created by : A.Murillo (Carduin-o)
* Using code from an algorithm course and personnal knowledge
* Last modification : 30-09-2019
* Particularities : Make sure you have jdom-2.0.6 up and running on your IDE!
*/

package manipXML;

//Requirements
import java.io.*;
import java.util.Iterator;
import java.util.List;

import org.jdom2.*;
import org.jdom2.input.SAXBuilder;
import org.jdom2.output.*;

public class manipulateurXML {

	Element racine; // The root of the XML file

	org.jdom2.Document document; // The "document" itself, as a memory variable

	// Getters and setters
	public Element getRacine() {
		return racine;
	}

	public void setRacine(Element racine) {
		this.racine = racine;
	}

	public org.jdom2.Document getDocument() {
		return document;
	}

	public void setDocument(org.jdom2.Document document) {
		this.document = document;
	}

	// Depending on how you want to create the file, the parameters nomRacine or
	// fichier might
	// be empty
	public manipulateurXML(String nomRacine, Boolean aPartirDunDocumentExistant, String fichier) {

		if (aPartirDunDocumentExistant) {
			deFichierXMLversJDOM(fichier);
		} else {
			racine = new Element(nomRacine);
			this.document = new Document(racine);
		}

	}

	// Imports a XML file in the source folder into JDOM format
	public void deFichierXMLversJDOM(String fichier) {
		// Créer une instance de SAXBuilder
		SAXBuilder sxb = new SAXBuilder();
		try {
			// Crer le document JDOM avec en argument le fichier XML
			document = sxb.build(new File(fichier));
			racine = document.getRootElement();
		} catch (Exception e) {
		}
	}

	// Displays document in command prompt
	public void affiche() {

		try {
			// Using classical format (pretty) other values : raw and compact
			XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());

			// Using System.out to display in command prompt
			sortie.output(document, System.out);
		} catch (java.io.IOException e) {
			/* No exceptions yet ! */}

	}

	// Display grandchild names from a child element
	public void afficherPetitFilsDeLaRacine(String nomDeFils, String nomDePetitFils) {

		// Get root
		Element racine = document.getRootElement();

		// Get wanted child elements into a list
		List<Element> listFils = racine.getChildren(nomDeFils);

		for (int i = 0; i < listFils.size(); i++) {

			// Get i-ish element of list
			Element courant = listFils.get(i);

			// Print
			System.out.println(courant.getChild(nomDePetitFils).getText());
		}

	}

	// Deletes grand child from child
	public void supprimerPetitFils(String fils, String petitFils) {

		// Get root
		Element racine = document.getRootElement();

		// Get childs into a list
		List<Element> listFils = racine.getChildren();

		// Putting in place iterator instead of for loop because the function messes
		// with
		// list length
		Iterator<Element> i = listFils.iterator();

		// Loop
		while (i.hasNext()) {
			// Move to next element
			Element courant = (Element) i.next();

			// If we find the grandchild we want to delete
			if (courant.getChild(petitFils) != null) {
				// Remove
				courant.removeChild(petitFils);

				// Set new name for modified child element
				courant.setName(courant.getName() + "_modifie");
			}
		}
	}

	// Deletes child from root using the content of a child element
	public void supprimerFils(String fils, String contenu) {

		// Get root
		Element racine = document.getRootElement();

		// Get childs into a list
		List<Element> listFils = racine.getChildren();

		// Putting in place iterator instead of for loop because the function messes
		// with
		// list length
		Iterator<Element> i = listFils.iterator();

		// Loop
		while (i.hasNext()) {
			// Move to next element
			Element courant = (Element) i.next();

			// If we find the grandchild we want to delete
			if (courant.getChild(fils).getText().equals(contenu)) {
				// Remove
				i.remove();
			}
		}

	}

	// Displays attributes of a child element
	public void afficherAttributFilsDeLaRacine(String nomDeFils, String nomAttribut) {

		// Get root
		Element racine = document.getRootElement();

		// Get wanted child elements into a list
		List<Element> listFils = racine.getChildren(nomDeFils);

		for (int i = 0; i < listFils.size(); i++) {

			// Get i-ish element of list
			Element courant = listFils.get(i);

			// Print
			System.out.println(courant.getAttributeValue(nomAttribut));
		}

	}

	// Saves the document into a "physical" file refered to using path as argument
	public void enregistre(String fichier) {

		try {
			// Using classical format (pretty) other values : raw and compact
			XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());

			// Using FileOutputStream this time to create file
			sortie.output(document, new FileOutputStream(fichier));
		}

		catch (java.io.IOException e) {
			/* No exceptions yet ! */}
	}

	// Adds element (with a name) to a given parent
	public Element ajouterElement(String nom, Element parent) {
		Element element = new Element(nom);
		parent.addContent(element);

		/*
		 * Returns element, this means the function must be used this way : Element e =
		 * ajouterElement("Test", parent); This is to allow you to use the created
		 * element later
		 */
		return element;
	}

	// Adds an atribute (with a name, and a value) to a given parent
	public void ajouterAttribut(String nomAttribut, String valeurAttribut, Element element) {

		Attribute attribut = new Attribute(nomAttribut, valeurAttribut);
		element.setAttribute(attribut);
	}

	// Adds an element with text between the markers to a given parent
	public Element ajouterElementTexte(String nom, String texte, Element parent) {

		Element element = new Element(nom);
		element.setText(texte);
		parent.addContent(element);

		/*
		 * Returns element, this means the function must be used this way : Element e =
		 * ajouterElement("Test", parent); This is to allow you to use the created
		 * element later
		 */
		return element;
	}

}
