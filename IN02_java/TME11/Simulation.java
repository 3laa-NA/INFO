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

        try{

            if(m>nbLignes*nbColonnes){
                throw new NombreObjetsTresGrand("Il est impossible de placer "+m+" objets dans une grille "+nbLignes+"x"+nbColonnes+" !");
            }

            grille = new Grille(nbLignes, nbColonnes);
            agent = new Agent4(grille);

            tab = new ArrayList<Contenu>() ;

            //on place les m contenu
            for(int i=0; i<m; i++){

                Contenu e;

                if (Math.random()< 0.8){
                    e = new Joyau((Math.random()<0.5) ? "Emeraude" : "Diamant");
                }else{
                    if(Math.random()<0.5)
                        e = new Gardien();
                    else
                        e = new SuperGardien();
                }

                //une varaible qui indique si la case choisi est occupee ou non
                boolean caseOccupee = true;

                //tant que la case choisi est occupee on recommence
                while(caseOccupee){
                    int x = (int)(Math.random()*nbLignes);
                    int y = (int)(Math.random()*nbColonnes);

                    if(grille.caseEstVide(x, y)){
                        grille.setCase(x, y, e);
                        e.setPosition(x,y);
                        tab.add(e);
                        caseOccupee = false;
                    }
                }
            }

            agent.seDeplacer(0, 0);

        }catch(NombreObjetsTresGrand e){

        }
    }

    public String toString() {

        //on va donner les informations sur le grille est son contenu
        String res = grille + "\n";
		for (Contenu r : tab) {
			res +=r + "\n";
		}

        //puis sur l'agent
        res+= "\n" + agent;

        //mais avant on affiche le grille
        grille.affiche(8);

        return res;
    }

    public void affiche(){grille.affiche(8);}
    
    //une fonction récursive
    public void lance(int nbEtapes){

        //condition de sortie
        if(nbEtapes==0){
            System.out.println("---------------FIN DE SIMULATION---------------\n\n");
            System.out.println(this);
            return;
        }

        try{
            int newx = agent.getX() + ((Math.random()<0.33) ? 1 : ((Math.random()<0.5) ? 0 : -1));
            int newy = agent.getY() + ((Math.random()<0.33) ? 1 : ((Math.random()<0.5) ? 0 : -1));

            if(Math.random()<0.3){
                int force = (int)(Math.random()*91 +10);
                agent.seDeplacer(newx, newy, force);
            }else{
                agent.seDeplacer(newx, newy);
            }

            int nb_teleportations = 0;
            int nb_super_guardien = 0;

            for (Contenu contenu : tab) {
                if (contenu instanceof SuperGardien) {

                    nb_super_guardien++;

                    int proba = (int)(Math.random()*91 +10); //la probabilité de se teleporter donné sur le modèle du choix de la force pour les agents

                    nb_teleportations += ((SuperGardien) contenu).seTeleporter(grille, proba);

                    // vérifie si le gardien s'est téléporté dans la même case que l'Agent4
                    if (agent.getX() == ((Gardien)contenu).getX() && agent.getY() == ((Gardien)contenu).getY()) {
                        // l'Agent4 perd tous ses joyaux
                        agent.viderSacJoyaux();
                        System.out.println("L'un des gardiens s'est déplacer dans la case de l'agent et a vider son sac !");
                    }

                }

            }

            System.out.println(nb_teleportations + " super guardien/s sur " + nb_super_guardien + " se sont/s'est teleporté!\n");

            //on relance avec (nbEtapes-1)
            lance(nbEtapes-1);

        }catch(DeplacementIncorrectException e){
            lance(nbEtapes); //lors d'un mauvais déplacement on relance avec le meme (nbEtapes)
        }

    }

}
