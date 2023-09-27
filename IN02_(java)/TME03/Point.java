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

        return "(" + posx + ", " + posy + ")" ;
    }
   

}
