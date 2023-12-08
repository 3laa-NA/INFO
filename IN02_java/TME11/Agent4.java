/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class Agent4 {
    private int x,y;
    private ArrayList<Joyau> sacJoyaux;
    private Grille grille;

    public Agent4 (int x, int y, Grille gr){
        this.x = x;
        this.y = y;
        grille = gr;
    }

    public void seDeplacer(int xnew, int ynew) throws DeplacementIncorrectException{
        if(x<0 || x>grille.nbLignes || y<0 || y>grille.nbColonnes){
            throw new DeplacementIncorrectException;
        }

        x=xnew;
        y=ynew;

        Contenu case = grille.getCase(xnew,ynew);

        if (case instanceof Joyau){
            sacJoyaux.add((Joyau)case);
            grille.videCase(xnew,ynew);
        }

        if(case instanceof Gardien){
            sacJoyaux.clear();
        }

    }

    public void seDplacer(int xnew, int ynew, int f) throws DeplacementIncorrectException{
        
        if(x<0 || x>grille.nbLignes || y<0 || y>grille.nbColonnes){
            throw new DeplacementIncorrectException;
        }

        x=xnew;
        y=ynew;

        Contenu case = grille.getCase(xnew,ynew);

        if (case instanceof Joyau){
            sacJoyaux.add((Joyau)case);
            grille.videCase(xnew,ynew);
        }

        if(case instanceof Gardien){
            Gardien gard = (Gardien) case;
            if(gard.getHp() <= f){
                grille.videCase(xnew,ynew);
            }
            else{
                sacJoyaux.clear();
                gard.hit(f);
            }
            
        }
    }
}
