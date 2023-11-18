public class TestForet {
    public static void main(String[] args) {
        Foret f1 = new Foret(4);
        
        for(int i=0; i < 10 ; i++){
            if(Math.random()<0.3){
                Arbre a1 = new Arbre("pin");
                boolean b = false;
                while(!b){
                    b = f1.placer(a1);
                }
            }
            else if(Math.random()<0.8){
                Champignon ch1 = new Champignon("cepe");
                boolean b = false;
                while(!b){
                    b = f1.placer(ch1);
                }
            }
            else{
                ChampignonToxique cht1 = new ChampignonToxique("amanites");
                boolean b = false;
                while(!b){
                    b = f1.placer(cht1);
                }
            }
        }

        System.out.println(f1.toString());
        
        Panier p1 = new Panier(8.);

        f1.ramasser(p1);

        System.out.println(p1.toString());
    }
}
