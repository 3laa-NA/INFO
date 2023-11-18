public class Ellipse extends Figure2D {
    private double grand, petit;

    public Ellipse(double g, double p){
        grand=g;
        petit=p;
    }

    public double surface(){
        return Math.PI*grand-petit ;
    }

    public double perimetre(){
        return 2*Math.PI*Math.sqrt((Math.pow(grand, 2) + Math.pow(petit, 2))/2);
    }
}
