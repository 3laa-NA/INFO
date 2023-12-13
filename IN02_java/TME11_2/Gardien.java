/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class Gardien extends Contenu implements Teleportable{
    private int hp;
    private static int cpt=0;
    private final int id;

    public Gardien(){
        super("Gardien",1);
        hp=(int)(Math.random()*201);
        cpt++;
        id=cpt;
    }
    public int getHp(){return hp;}

    //simulation d'une frappe par l'agent
    public void hit(int f){
        hp-=f;
    }

    public void seTeleporter(Grille grille) throws CoordonneesIncorrectesException {
        if (Math.random() < 0.3) {
            int x, y;

            do {
                x = (int) (Math.random() * grille.nbLignes);
                y = (int) (Math.random() * grille.nbColonnes);
            } while (!grille.caseEstVide(x, y));

            try {
                grille.videCase(super.getX(), super.getY());
            } catch (CaseNonPleineException e) {

            }

            // chercher une case vide tant que la case de destination n'est pas vide
            while (!grille.caseEstVide(x, y)) {
                x = (int) (Math.random() * grille.nbLignes);
                y = (int) (Math.random() * grille.nbColonnes);
            }

            // placer le gardien dans la nouvelle case
            try {
                grille.setCase(x, y, this);
            } catch (CoordonneesIncorrectesException e) {
                
            }

            // met à jour la position du Gardien
            super.setPosition(x, y);
        }
    }

}