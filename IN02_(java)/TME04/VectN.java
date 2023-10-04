import java.util.Random;
import java.util.Arrays;

public class VectN{
    private int []tab;

    public VectN(int n){
        this.tab = new int [n];
    }

    public VectN(int n, int valMAX){
        this(n);
        for(int i=0 ; i<n; i++){
            this.tab[i]= (int)(Math.random()*valMAX+1);
        }
    }

    public VectN(){
        this(5,9);
    }

    public VectN(int a,int b,int c){
        this(3);
        this.tab[0]=a;
        this.tab[1]=b;
        this.tab[2]=c;
    }

    public void affiche(){

        for (int x : this.tab){
            System.out.print(x + " ");
        }
        System.out.println(" ");
    }

    public int somme(){
        int res=0;
        for(int x : this.tab){
            res += x ; 
        }
        return res;
    }

    public String toString() {
        return Arrays.toString(tab);
    }

    int [] getTab(){
        return this.tab;
    }

    public int[] getTab2() {
        return Arrays.copyOf(tab, tab.length);
    }
    

    public static void main(String[] args) {
        VectN v = new VectN();
        VectN v2 = new VectN(9);
        VectN v3 = new VectN(10,15);
        VectN v4 = new VectN(1,2,3);

        v.affiche();
        v2.affiche();
        v3.affiche();
        v4.affiche();

        System.out.println(v.somme());

        System.out.println(v.toString());

        VectN vect = new VectN ( 4 , 5 , 6 ) ;
        int [] tab=vect.getTab() ;
        tab [0] = 100;
        System.out.println(vect);

    }

}