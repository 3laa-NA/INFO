public class TestTriangle{
    public static void main(String[] args) {
        Point p1 = new Point();
        Point p2 = new Point();
        Point p3 = new Point();

        Triangle t1 = new Triangle(p1, p2, p3);

        System.out.println("p1 : " + p1.toString());
        System.out.println("p2 : " + p2.toString());
        System.out.println("p3 : " + p3.toString());

        System.out.println("distance p1 à p2 : " + p1.distance(p2));

        System.out.println("t1 : " + t1.toString());

        System.out.println("le périmètre de t1 est de " + t1.getPerimetre());

        Triangle t2 = new Triangle(t1);

        System.out.println("t2 : " + t2.toString());

        p1.deplaceToi(7.3, 3.7);

        System.out.println("t1 apres deplacement de p1 : " + t1.toString());

        System.out.println("t2 apres deplacement de p1 : " + t2.toString());



    }
}