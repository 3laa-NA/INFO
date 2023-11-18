public class TestTableauMain {
    public static void main(String[] args) {
        
        System.out.println("Il y a " + args.length + " arguments");

        int i = 0;
        for (String x : args){
            System.out.println("args[" + i + "]=" + x);
            i++;
        }
    }
}