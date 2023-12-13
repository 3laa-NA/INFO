/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class SuperGardien extends Gardien implements Teleportable {
    public int seTeleporter(Grille grille, double proba){

        //indique si oui ou non le Super guardien s'est teleporte
        int teleportation = 0;

        if (Math.random() < proba) {
            try {

                teleportation++;

                int x, y;
                
                // chercher une case vide tant que la case de destination n'est pas vide
                do {
                    x = (int) (Math.random() * grille.nbLignes);
                    y = (int) (Math.random() * grille.nbColonnes);
                } while (!grille.caseEstVide(x, y));

                //vider la case courante et placer le gardien dans la nouvelle case
                grille.setCase(x, y, grille.videCase(getX(), getY()));

                System.out.println("Un super gardien s'est teleporté aux coordonnees ("+x+", "+y+")!");
                
                // met à jour la position du Gardien
                super.setPosition(x, y);

            }catch (CoordonneesIncorrectesException e) {
                System.out.println(e);
            }catch (CaseNonPleineException e) {
                System.out.println(e);
            }

        }

        return teleportation;
    }
}