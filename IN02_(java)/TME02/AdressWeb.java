public class AdressWeb {

    private String protocole;
    private String domaine;
    private String chemin;

    public AdressWeb(String protocole, String domaine, String chemin) {
        this.protocole = protocole;
        this.domaine = domaine;
        this.chemin = chemin;
    }

    public AdressWeb(String domaine, String chemin) {
        this("https", domaine, chemin);
    }

    public AdressWeb(String domaine) {
        this(domaine, "");
    }

    public String toString() {
        return protocole + "://www." + domaine + chemin;
    }

}