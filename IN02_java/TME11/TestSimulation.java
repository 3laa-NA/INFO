/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class TestSimulation {

    public static void main(String[] args) {

        try{

            //on crée l'environement pour la simulation

            //les dimensions de la grille: ↓   ↓
            Simulation s1 = new Simulation(10, 10, 24);
            //nombre objets à placer:              ↑


            //on affiche l'etat du grille/simulation au départ
            System.out.println("Etat du grille au départ:");
            s1.affiche();

            //on lance la simulation
            s1.lance(20);
            //       ↑ nombre d'iterations

        }catch(CoordonneesIncorrectesException e){
            System.out.println(e);
        }
        catch(DeplacementIncorrectException e){
            System.out.println(e);
        }

    }

}
