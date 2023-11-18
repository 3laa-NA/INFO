import java.text.DecimalFormat;

public class Champignon implements Ramassable {
    private String nom;
    private double poids;
    
    public Champignon(String nom){
        this.nom = nom;
        poids = Math.random() * 3;
    }

    public double getPoids() {
        return poids;
    }

    public String toString() {
        DecimalFormat df = new DecimalFormat("#.##");
        return nom + " " + Double.parseDouble(df.format(poids)) + "kg";
    }
}
