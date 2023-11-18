public class TrianglePascal{
    private int [][] tab;

    public TrianglePascal(int n){
        this.tab = new int[n][];
    }

    public void remplirTriangle(){
        for(int i=0 ; i < this.tab.length ;i++){
            tab[i] = new int[i + 1];
            for (int j=0 ; j <=i ; j++){
                if( j==0 || j==i ){
                    tab[i][j] = 1;    
                }
                else{
                    tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
                }
            }
        }
    }

    public String toString(){
        String res= "";
        for (int i=0 ; i < this.tab.length ;i++){
            for (int j=0 ; j <=i ; j++){
                res += tab[i][j] + "|";
            }
            res += "\n";
        }
        return res;
    }

}