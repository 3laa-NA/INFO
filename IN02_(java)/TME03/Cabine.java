public class Cabine {
    private double volume;
    private String couleur;

    public Cabine(double volume, String couleur)
    {
        this.volume = volume;
        this.couleur = couleur;
    }

    public void setCouleur(String couleur)
    {
        this.couleur = couleur;
    }

    public Cabine(Cabine c1){
        this.couleur = c1.couleur;
        this.volume = c1.volume;
        
    }

    public String toString ()
    {
        return "volume = " + volume + " m3, couleur = " + couleur;
    }

}
