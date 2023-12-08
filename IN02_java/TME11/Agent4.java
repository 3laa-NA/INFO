/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

import java.util.ArrayList;

public class Agent4 {
    private int x,y;
    private ArrayList<Joyau> sacJoyaux;
    private Grille grille;

    public Agent4 (Grille gr){
        grille = gr;
        sacJoyaux = new ArrayList<Joyau> ();
    }

    //la méthode renverra des informations sur ce qui s’est produit durant le déplacement
    public String seDeplacer(int xnew, int ynew) throws DeplacementIncorrectException{
        if(xnew<0 || xnew>grille.nbLignes || ynew<0 || ynew>grille.nbColonnes){
            throw new DeplacementIncorrectException();
        }

        String res="";

        x=xnew;
        y=ynew;
        Contenu c1 = null;

        try{

            c1 = grille.getCase(xnew,ynew);
            
            if (c1 instanceof Joyau){
                sacJoyaux.add((Joyau)c1);
                grille.videCase(xnew,ynew);
                res = "L'agent a trouvé un joyau!";
            }

        }catch(CoordonneesIncorrectesException e){

        }catch(CaseNonPleineException e){
            
        }

        if(c1 instanceof Gardien){
            sacJoyaux.clear();
            res = "L'agent s'est fait arrêter par un gardien!";
        }

        return res;

    }

    //la méthode renverra des informations sur ce qui s’est produit durant le déplacement
    public String seDeplacer(int xnew, int ynew, int f) throws DeplacementIncorrectException{
        
        if(xnew<0 || xnew>grille.nbLignes || ynew<0 || ynew>grille.nbColonnes){
            throw new DeplacementIncorrectException();
        }

        String res="";

        x=xnew;
        y=ynew;
        Contenu c1 = null;

        try{

            c1 = grille.getCase(xnew,ynew);
            
            if (c1 instanceof Joyau){
                sacJoyaux.add((Joyau)c1);
                grille.videCase(xnew,ynew);
                res = "L'agent a trouvé un joyau!";
            }
            
            if(c1 instanceof Gardien){
                Gardien gard = (Gardien) c1;
                if(gard.getHp() <= f){
                    grille.videCase(xnew,ynew);
                    res = "L'agent a tué un gardien!";
                }
                else{
                    sacJoyaux.clear();
                    gard.hit(f);
                    res = "L'agent s'est fait arrêter par un gardien!(gardien blessé)";
                }
                
            }

        }catch(CoordonneesIncorrectesException e){

        }catch(CaseNonPleineException e){
            
        }

        return res;
        
    }

    public int fortune(){
        int res = 0;
        for(Joyau j : sacJoyaux){
            res+=j.getPrix();
        }
        return res;
    }

    public String contenuSac(){
        int nb_emeraude = 0;
        int nb_diamant = 0;
        int autres = 0;

        for(Joyau j : sacJoyaux){
            if("Diamant".equals(j.getType())){
                nb_diamant++;
            }else if("Emeraude".equals(j.getType())){
                nb_emeraude++;
            }else{autres++;}
        }

        return "Le sac de l'agent contient " + nb_diamant + " diamants, " + nb_emeraude + " emeraude, et " + autres + " joyaux d'autre/s type/s";
    }
    
    public String toString() {
        return "L'agent 4 est actuellement en position ("+x+", "+y+")" + " avec un sac contenant "+sacJoyaux.size()+" joyaux et une fortune égale à " + fortune() + " pièces d'or.\n" + contenuSac();
    }

    public int getX(){return x;}

    public int getY(){return y;}

}