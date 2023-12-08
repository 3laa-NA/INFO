/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class TestSimulation {
    public static void main(String[] args) {

        try{

            Simulation s1 = new Simulation(5, 5, 10);
            System.out.println("Etat du grille au départ:");
            s1.affiche();

            s1.lance(15);

        }catch(CoordonneesIncorrectesException e){
            System.out.println(e);
        }
        catch(DeplacementIncorrectException e){
            System.out.println(e);
        }
    }
}
