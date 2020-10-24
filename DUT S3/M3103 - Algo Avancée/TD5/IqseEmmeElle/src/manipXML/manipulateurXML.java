/*
* Created by : A.Murillo (Carduin-o)
* Using code from an algorithm course and personnal knowledge
* Last modification : 30-09-2019
* Particularities : Make sure you have jdom-2.0.6 up and running on your IDE!
*/

package manipXML;

//Requirements
import java.io.*;
import org.jdom2.*;
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

	public manipulateurXML(String nomRacine) {
		
		//Creating root
		racine = new Element(nomRacine);

		//Creating document
		document = new Document(racine);
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
