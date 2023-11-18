public class TestTrianglePascal{
    public static void main(String[] args) {
        TrianglePascal t1 = new TrianglePascal(5);
        t1.remplirTriangle();
        
        System.out.print("t1 (n=5) :\n" + t1.toString() + "\n");


        TrianglePascal t2 = new TrianglePascal(10);
        t2.remplirTriangle();
        
        System.out.print("t2 (n=10) :\n" + t2.toString() + "\n");


        TrianglePascal t3 = new TrianglePascal(20);
        t3.remplirTriangle();
        
        System.out.print("t3 (n=20) :\n" + t3.toString() + "\n");
    }
}