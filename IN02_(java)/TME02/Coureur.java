import java.util.Random;

public class Coureur {

    private int numDossard;
    private double tempsAu100;
    private boolean possedeTemoin;

    public Coureur(int numDossard) {
        this.numDossard = numDossard;
        this.tempsAu100 = 12 + (Math.random()*4);
        this.possedeTemoin = false;
    }

    public Coureur() {
        this( (int) (Math.random() * 1000) +1 );
    }

    public int getNumDossard() {
        return numDossard;
    }

    public double getTempsAu100() {
        return tempsAu100;
    }

    public boolean getPossedeTemoin() {
        return possedeTemoin;
    }

    public void setPossedeTemoin(boolean possedeTemoin){
        this.possedeTemoin = possedeTemoin;
    }
    
    public String toString() {
        String possedeTemoinString = possedeTemoin ? "oui" : "non";
        return "Coureur " + numDossard + " tempsAu100 : " + String.format("%.1f", tempsAu100) + "s au 100m possedeTemoin : " + possedeTemoinString;
    }

    public void passeTemoin(Coureur c){
        this.possedeTemoin = false;
        c.possedeTemoin = true;
        System.out.println("moi, coureur " + this.numDossard + ", je passe le témoin au coureur " +  c.numDossard );
    }

    public void courir(){
        System.out.println("je suis le coureur " + this.numDossard + " et je cours" );
    }
    
}