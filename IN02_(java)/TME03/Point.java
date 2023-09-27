import java.text.DecimalFormat;

public class Point {
    private double posx, posy;

    public Point(int posx, int posy){
        this.posx = posx;
        this.posy = posy;
    }
    
    public Point (){
        this.posx = Math.random() * 9;
        this.posy = Math.random() * 9;
    }

    public String toString (){

        DecimalFormat df = new DecimalFormat("#.##"); 
        return "(" + df.format(posx) + ", " + df.format(posy) + ")" ;
    }
   
    public double distance(Point p){
        double x1 = this.posx;
        double y1 = this.posy;
        double x2 = p.posx;
        double y2 = p.posy;

        return Math.sqrt( Math.pow((x2-x1),2.0) + Math.pow((y2-y1),2.0) );
    }

    public void deplaceToi(int newx, int newy){
        this.posx = newx;
        this.posy = newy;
    }

}
