import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Tournoi {
	
	private String nom;
	private List<Equipe> listeEquipes = new ArrayList<Equipe>();
	private Map <String,String> palmares = new HashMap <String,String>();
	
	
	public Tournoi (String nom) {
		this.nom = nom;
	}
	
	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public List<Equipe> getListeEquipes() {
		return listeEquipes;
	}

	public Map<String, String> getPalmares() {
		return palmares;
	}

	public void inscrirePalmares (String annee, Equipe equipe) {
		palmares.put(annee, equipe.getNom());
	}
	
	public void desinscrirePalmares(String annee) {
		palmares.remove(annee);
	}
	
	public void ajouteEquipe (Equipe equipe) {
		listeEquipes.add(equipe);
	}
	
	public void enleveEquipe (Equipe equipe) {
		listeEquipes.remove(equipe);
	}


	
}


