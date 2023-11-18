import java.util.ArrayList;

public class Foret {
    private Object[][] terrain;

    public Foret(int taille){
        terrain = new Object[taille][taille];
    }

    public boolean placer(Object obj){
        int x = (int) (Math.random() * terrain.length);
        int y = (int) (Math.random() * terrain.length);
        if(terrain[x][y]==null){
            terrain[x][y]=obj;
            return true;
        }
        return false;
    }

    public String toString(){
        String res = "";
        for(int i=0;i<terrain.length;i++){
            res += "|";
            for(int j=0;j<terrain.length;j++){
                Object tmp = terrain[i][j];
                if(tmp != null){
                    res += tmp.toString().charAt(0);
                }
                else{res+=' ';}
            }
            res += "|\n";
        }
        return res;
    }

    public ArrayList<Champignon> ramasserChampignons(){
        ArrayList<Champignon> res = new ArrayList<Champignon>();
        for(int i=0;i<terrain.length;i++){
            for(int j=0;j<terrain.length;j++){
                if((terrain[i][j]) instanceof Champignon){
                    res.add((Champignon)terrain[i][j]);
                    terrain[i][j] = null;
                }
            }
        }
        return res;
    }

    public ArrayList<Ramassable> ramasserTout(){
        ArrayList<Ramassable> res = new ArrayList<Ramassable>();
        for(int i=0;i<terrain.length;i++){
            for(int j=0;j<terrain.length;j++){
                if((terrain[i][j]) instanceof Ramassable){
                    res.add((Ramassable)terrain[i][j]);
                    terrain[i][j] = null;
                }
            }
        }
        return res;
    }

    public void ramasser(Panier p){
        for(int i=0;i<terrain.length;i++){
            for(int j=0;j<terrain.length;j++){
                if((terrain[i][j]) instanceof Ramassable){
                    p.add((Ramassable)terrain[i][j]);
                    terrain[i][j] = null;
                }
            }
        }
    }


}
