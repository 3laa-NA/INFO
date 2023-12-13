/*
 Alaa ALABOUD
 Ichraq MOHAMMAD
*/

public class Simulation {
    private Agent4 agent;
    private Grille grille;

    public Simulation(int nbLignes, int nbColonnes, int m) throws CoordonneesIncorrectesException, DeplacementIncorrectException{

        try{

            //dans le cas ou le nombre d'objets a placé est plus grand que le nombre de cases
            if(m>nbLignes*nbColonnes){
                throw new NombreObjetsTresGrand("Il est impossible de placer "+m+" objets dans une grille "+nbLignes+"x"+nbColonnes+" !");
            }

            //on initialise les attributs
            grille = new Grille(nbLignes, nbColonnes);
            agent = new Agent4(grille);

            //on place les m contenus
            for(int i=0; i<m; i++){

                Contenu e;

                if (Math.random()< 0.8){ //la probabilité que l'objet placé soit un joyau
                    e = new Joyau((Math.random()<0.5) ? "Emeraude" : "Diamant");
                }else{
                    if(Math.random()<0.5)//la probabilité que le gardien placé soit un super guardien
                        e = new SuperGardien();
                    else
                        e = new Gardien();
                }

                //une variable qui indique si la case choisie est occupée ou non
                boolean caseOccupee = true;

                //tant que la case choisi est occupée on recommence
                while(caseOccupee){
                    int x = (int)(Math.random()*nbLignes);
                    int y = (int)(Math.random()*nbColonnes);

                    if(grille.caseEstVide(x, y)){
                        grille.setCase(x, y, e);
                        e.setPosition(x,y);
                        caseOccupee = false;
                    }
                }
            }

            //agent.seDeplacer(0, 0);

        }catch(NombreObjetsTresGrand e){

        }
    }

    public String toString() {

        //on va donner des informations sur le grille est son contenu
        String res = grille + "\n\nLes contenus:\n";
		for (Contenu r : grille.lesContenus()) {
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
            System.out.println("---------------FIN DE SIMULATION---------------\n\nEtat du grille après la simulation:");
            System.out.println(this);
            return;
        }

        try{

            //on choisit une case voisine de la case courante
            int newx = agent.getX() + ((Math.random()<0.33) ? 1 : ((Math.random()<0.5) ? 0 : -1));
            int newy = agent.getY() + ((Math.random()<0.33) ? 1 : ((Math.random()<0.5) ? 0 : -1));

            if(Math.random()<0.3){//probabilité de se deplacer avec force
                int force = (int)(Math.random()*91 +10);//le choix d'une force entre 10 et 100
                agent.seDeplacer(newx, newy, force);
            }else{
                agent.seDeplacer(newx, newy);
            }

            System.out.println();
            
            int nb_teleportations = 0; //compteurs de super gardiens qui se sont téléporté
            int nb_super_guardien = 0; //compteurs de super gardiens

            for (Contenu contenu : grille.lesContenus()) {
                if (contenu instanceof SuperGardien){

                    nb_super_guardien++;

                    int proba = (int)(Math.random()*91 +10); //la probabilité de se téléporter donné sur le modèle du choix de la force pour les agents (une valeur entre 10-100)

                    nb_teleportations += ((SuperGardien) contenu).seTeleporter(grille, proba);

                    // vérifie si le gardien s'est téléporté dans la même case que l'Agent4
                    if (agent.getX() == ((Gardien)contenu).getX() && agent.getY() == ((Gardien)contenu).getY()) {
                        // l'Agent4 perd tous ses joyaux
                        agent.viderSacJoyaux();
                        System.out.println("Le super gardien s'est téléporté dans la case de l'agent et a vider son sac !");
                    }

                }

            }

            System.out.println(nb_teleportations + " super gardien/s sur " + nb_super_guardien + " s'est/se sont téléporté!\n");

            //on relance avec (nbEtapes-1)
            lance(nbEtapes-1);

        }catch(DeplacementIncorrectException e){
            lance(nbEtapes); //lors d'un mauvais déplacement on relance avec le meme (nbEtapes)
        }

    }

}
