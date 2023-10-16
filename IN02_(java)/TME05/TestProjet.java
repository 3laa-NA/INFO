public class TestProjet {
    public static void main(String[] args) {
        System.out.println("nbPersonnes=" + Personne.getNbPersonnes());

        Personne p1 = new Personne();
        Personne p2 = new Personne();
        System.out.println(p1.toString());
        System.out.println(p2.toString());


        System.out.println("nbPersonnes=" + Personne.getNbPersonnes());

        Projet pr1 = new Projet("P3X-774");
        System.out.println(pr1.toString());

        Projet pr2 = new Projet("P3R-233");
        System.out.println(pr2.toString());

        Projet pr3 = new Projet();
        System.out.println(pr3.toString());

        System.out.println("\nnbPersonnes = " + Personne.getNbPersonnes() + "\nnbTrios = " + Trio.getNbTrios() + "\nnbProjets = " + Projet.getNbProjet() );

    }
}
