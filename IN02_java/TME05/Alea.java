public class Alea {

    private Alea(){
        
    }

    public static char lettre(){
        int n = (int)(Math.random()*26) ;
        return (char) ('a' + n);
    }

    public static String chaine(){
        String ch = "";
        for (int i=0;i<10;i++){
            ch += Alea.lettre();
        }

        return ch;
    }

    public static void main(String[] args) {
        System.out.println(Alea.chaine());
    }
}
