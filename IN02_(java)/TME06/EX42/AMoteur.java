public class AMoteur extends Vehicule {
    private double cap, niv_ess=0;

    public AMoteur(String m, double cap){
        super(m);
        this.cap=cap;
    }

    public String toString(){
        return super.toString() + " a moteur";
    }

    public void approvisionner(double nbLitres){
        niv_ess+=nbLitres;
        if (niv_ess>cap){
            niv_ess=cap;
        }
    }

    public boolean enPanne(){
        return niv_ess==0;
    }

}
