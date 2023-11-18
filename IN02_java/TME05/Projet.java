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
        this.nom = Alea.chaine();
        this.tr = new Trio();
        cpt++;
    }

    public static int getNbProjet(){ return cpt; }

    public String toString(){
        return "Projet " + this.nom + " " + tr.toString() ;
    }
}
