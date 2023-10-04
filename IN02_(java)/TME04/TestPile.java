public class TestPile{
    public static void main(String[] args) {

        Pile p=new Pile(3);
        System.out.println(p.toString());
       

        Assiette a = new Assiette();

        p.empiler(a);
        p.empiler(a);
        p.empiler(a);

        System.out.println(p.toString());

        p.depiler();

        System.out.println(p.toString());

        p.empiler(a);
        p.empiler(a);

        System.out.println(p.toString());

        p.depiler();
        p.depiler();
        p.depiler();
        p.depiler();

        System.out.println(p.toString());
    }
}   