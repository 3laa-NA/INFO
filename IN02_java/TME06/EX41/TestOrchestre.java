public class TestOrchestre {
    public static void main(String[] args) {
        Guitare g1 = new Guitare("classique" , 2 , 500);
        Piano p1 = new Piano(88 , 300 , 700);

        System.out.println(g1.toString());
        System.out.println(p1.toString());

        Orchestre o1 = new Orchestre(5);

        o1.ajouterInstrument(g1);
        o1.ajouterInstrument(p1);

        o1.jouer();
    }
}
