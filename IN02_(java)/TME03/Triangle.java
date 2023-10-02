public class Triangle {
    private Point p1, p2, p3;

    public Triangle(Point p1, Point p2, Point p3){
        this.p1=p1;
        this.p2=p2;
        this.p3=p3;
    }

    public Triangle(){
        this.p1= new Point();
        this.p2= new Point();
        this.p3= new Point();
    }

    public String toString(){
        return "{" + this.p1.toString() + ";" + this.p2.toString() + ";" + this.p3.toString() + "}" ;
    }

    public double getPerimetre(){
        return p1.distance(p2) + p2.distance(p3) + p3.distance(p1) ;
    }

    public Triangle(Triangle t1){

        this.p1 = new Point(t1.p1);
        this.p2 = new Point(t1.p2);
        this.p3 = new Point(t1.p3);
    }
}