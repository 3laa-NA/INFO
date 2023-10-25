public class Rectangle extends Figure2D {
    private double longueur, larg;

    public Rectangle(double lo, double la){
        longueur=lo;
        larg=la;
    }

    public double surface(){
        return longueur*larg;
    }

    public double perimetre(){
        return (longueur*2) + (larg*2);
    }
}
