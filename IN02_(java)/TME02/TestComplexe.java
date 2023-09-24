public class TestComplexe {
    public static void main(String[] args) {
        Complexe z1 = new Complexe(1,0);
        Complexe z2 = new Complexe();
        Complexe z3 = new Complexe();

        System.out.println("z1 = " + z1.toString() );
        System.out.println("z2 = " + z2.toString() );
        System.out.println("z3 = " + z3.toString() );

        System.out.println("z1 reel? " + z1.estReel() );
        System.out.println("z2 reel? " + z2.estReel() );
        System.out.println("z3 reel? " + z3.estReel() );

        System.out.println("z2 + z3 = " + z2.addition(z3) );
        System.out.println("z2 * z3 = " + z2.multiplication(z3) );

    }
}