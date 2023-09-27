public class TesTracteur {
    public static void main(String[] args) {
        Roue r1 = new Roue(120);
        Roue r2 = new Roue(120);
        Roue r3 = new Roue();
        Roue r4 = new Roue();

        System.out.println(r1.toString());
        System.out.println(r2.toString());
        System.out.println(r3.toString());
        System.out.println(r4.toString());


        Cabine c1 = new Cabine(3,"Bleu");

        System.out.println(c1.toString());

        Tracteur t1 =new Tracteur(r1,r2,r3,r4,c1);

        System.out.println(t1.toString());

        Tracteur t2 = t1;

        t2.peindre("Rouge");

        System.out.println(t1.toString());

        t2 = new Tracteur(t1);

        t2.peindre("Vert");

        System.out.println(t1.toString());
    }


}