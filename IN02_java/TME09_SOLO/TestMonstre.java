public class TestMonstre {
    public static void main(String[] args) {
        Bande b1=new Bande(10);

        Kraken k1 = new Kraken(6,12,"geant");
        Kraken k2 = new Kraken(6,12,"");

        b1.ajouterMonstre(k1);
        b1.ajouterMonstre(k2);

        System.out.println(b1.toString());

        System.out.println("le total de degats infligés par l'attaque : " +b1.attaqueBande());

        Loup l1 = new Loup(8, "foret" , "brun");
        Loup l2 = new Loup(9, "plaine" , "blanc");

        b1.ajouterMonstre(l1);
        b1.ajouterMonstre(l2);

        System.out.println(b1.toString());

        System.out.println("le total de degats infligés par l'attaque : " +b1.attaqueBande());


    }    
}
