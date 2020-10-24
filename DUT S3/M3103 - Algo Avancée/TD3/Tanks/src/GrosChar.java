
public class GrosChar extends CharBouclier{
	
	private final int BOOST_CARBURANT_DEFAUT = getVolumeCarburant()*2;
	
	public int getBOOST_CARBURANT_DEFAUT() {
		return BOOST_CARBURANT_DEFAUT;
	}
	
	public GrosChar (String nom) {
		super (nom);
		setBouclier(1);
		setVolumeCarburant(BOOST_CARBURANT_DEFAUT);
	}

}
