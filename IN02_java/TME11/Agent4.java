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
        sacJoyaux = new ArrayList<Joyau>();
    }

    public void seDeplacer(int xnew, int ynew) throws DeplacementIncorrectException{

        //on leve une exception si les coordonnées ne sont pas valides
        if(!grille.sontValides(xnew,ynew)){
            throw new DeplacementIncorrectException();
        }

        x=xnew;
        y=ynew;
        Contenu c1 = null;

        try{

            c1 = grille.getCase(xnew,ynew);

            System.out.println("L'agent s'est deplacé aux coordonnées ("+xnew+", "+ynew+")!");
            
            if (c1 instanceof Joyau){
                sacJoyaux.add((Joyau)c1);
                grille.videCase(xnew,ynew);
                System.out.println("L'agent a trouvé un joyau!");
            }
            
            if(c1 instanceof Gardien){
                sacJoyaux.clear();
                System.out.println("L'agent s'est fait arrêter par un gardien!");
            }

        }catch(CoordonneesIncorrectesException e){
            System.out.println(e);
        }catch(CaseNonPleineException e){
            System.out.println(e);
        }


    }

    public void seDeplacer(int xnew, int ynew, int f) throws DeplacementIncorrectException{
        
        //on leve une exception si les coordonnées ne sont pas valides
        if(!grille.sontValides(xnew,ynew)){
            throw new DeplacementIncorrectException();
        }

        x=xnew;
        y=ynew;
        Contenu c1 = null;

        try{

            c1 = grille.getCase(xnew,ynew);
            
            System.out.println("L'agent s'est deplacé aux coordonnées ("+xnew+", "+ynew+")!");
            
            if (c1 instanceof Joyau){
                sacJoyaux.add((Joyau)c1);
                grille.videCase(xnew,ynew);
                System.out.println("L'agent a trouvé un joyau!");
            }
            
            if(c1 instanceof Gardien){
                Gardien gard = (Gardien) c1;
                if(gard.getHp() <= f){
                    grille.videCase(xnew,ynew);//on supprime le gardien (il est mort)
                    System.out.println("L'agent a tué un gardien!");
                }
                else{
                    sacJoyaux.clear();
                    gard.hit(f); //on simmule l'attaque en retirant des hp au gardien
                    System.out.println("L'agent s'est fait arrêter par un gardien!(gardien blessé)");
                }
                
            }

        }catch(CoordonneesIncorrectesException e){
            System.out.println(e);
        }catch(CaseNonPleineException e){
            System.out.println(e);
        }
        
    }

    public int fortune(){
        int res = 0;
        for(Joyau j : sacJoyaux){
            res+=j.getPrix();
        }
        return res;
    }

    public String contenuSac(){

        //on initialise les compteurs
        int nb_emeraudes = 0;
        int nb_diamants = 0;
        int autres = 0;

        for(Joyau j : sacJoyaux){
            if("Diamant".equals(j.getType())){
                nb_diamants++;
            }else if("Emeraude".equals(j.getType())){
                nb_emeraudes++;
            }else{autres++;}
        }

        return "Le sac de l'agent contient " + nb_diamants + " diamants, " + nb_emeraudes + " emeraude, et " + autres + " joyaux d'autre/s type/s";
    }
    
    public String toString() {
        //on affiche des informations sur l'agent et son sac
        return "L'agent 4 est actuellement en position ("+x+", "+y+")" + " avec un sac contenant "+sacJoyaux.size()+" joyaux et une fortune égale à " + fortune() + " pièces d'or.\n" + contenuSac();
    }

    public int getX(){return x;}

    public int getY(){return y;}

    public void viderSacJoyaux() {
        sacJoyaux.clear();
    }

}