public class Projet {
    private String nom;
    private Trio tr;
    private static int cpt= 0;

    public Projet(String s){
        this.nom = s;
        this.tr = new Trio();
        cpt++;
    }

    public Projet(){
        this(Alea.chaine());
    }

    public static int getNbProjet(){ return cpt; }

    public String toString(){
        return "Projet " + this.nom + " " + tr ;
    }
}
