public class Roue {
    private int diametre;

    public Roue (int diametre)
    {
        this.diametre = diametre;
    }

    public Roue()
    {
        this(60);
    }

    public Roue(Roue r1){
        this.diametre = r1.diametre;
    }

    public String toString()
    {
        return "Le diametre de la roue est : "+ diametre;
    }

}
