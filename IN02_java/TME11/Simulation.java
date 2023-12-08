/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

import java.util.ArrayList;

public class Simulation {
    private Agent4 agent;
    private Grille grille;
    private ArrayList<Contenu> tab;

    public Simulation(int nbLignes, int nbColonnes, int m) throws CoordonneesIncorrectesException, DeplacementIncorrectException{
        grille = new Grille(nbLignes, nbColonnes);
        agent = new Agent4(grille);

        tab = new ArrayList<Contenu>() ;

        for(int i=0; i<m; i++){
            Contenu e;
            if (Math.random()< 0.5){
                e = new Joyau((Math.random()<0.5) ? "Emeraude" : "Diamant");
            }else{ e = new Gardien();}
            
            grille.setCase((int)(Math.random()*nbLignes), (int)(Math.random()*nbColonnes), e);

            tab.add(e);
        }

        String wtv = agent.seDeplacer(0, 0);
    }

    public String toString() {
        String res = grille + "\n";
		for (Contenu r : tab) {
			res +=r + "\n";
		}
        res+= "\n" + agent;

        grille.affiche(8);

        return res;
    }

    public void affiche(){grille.affiche(8);}
    
    public void lance(int nbEtapes){

        if(nbEtapes==0){
            System.out.println("---------------FIN DE SIMULATION---------------\n\n");
            System.out.println(this);
            return;
        }

        try{
            int newx = agent.getX() + ((Math.random()<0.5) ? 1 : -1);
            int newy = agent.getY() + ((Math.random()<0.5) ? 1 : -1);

            if(Math.random()<0.3){
                int force = (int)(Math.random()*91 +10);
                String res= agent.seDeplacer(newx, newy, force);
                System.out.println("L'agent s'est deplacé aux coordonnees ("+newx+", "+newy+") avec une force de " + force + "!\n"+res+"\n");
            }else{
                String res = agent.seDeplacer(newx, newy);
                System.out.println("L'agent s'est deplacé aux coordonnees ("+newx+", "+newy+")!\n"+res+"\n");
            }

            lance(nbEtapes-1);

        }catch(DeplacementIncorrectException e){
            lance(nbEtapes);
        }

    }

}
