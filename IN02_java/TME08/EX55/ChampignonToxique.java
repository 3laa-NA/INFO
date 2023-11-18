import java.text.DecimalFormat;

public class ChampignonToxique implements Ramassable, Toxique {
    private String nom;
    private double poids;
    
    public ChampignonToxique(String nom){
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

