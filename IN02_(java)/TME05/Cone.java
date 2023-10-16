public class Cone {
    private double r, h;
    private final double pi = 3.14159 ;
    private static int nbCones =  0;

    public Cone(double r, double h){
        this.r = r;
        this.h = h;
        nbCones++;
    }

    public Cone(){
        this(Math.random()*10 , Math.random()*10);
    }

    
    public double getVolume(){
        return (1/3)*pi*r*r;
    }

    public String toString(){
        return "Cone r=" + h + " h=" + h + " V=" +  this.getVolume();
    }

    public static int nbCones(){ return nbCones; }


}
