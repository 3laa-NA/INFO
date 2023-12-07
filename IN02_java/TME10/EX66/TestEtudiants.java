public class TestEtudiants {
    public static void main(String[] args) {
        for(String str : args){
            try{
                System.out.print(Integer.parseInt(str) + " est une note, ");
            }catch(NumberFormatException e){
                System.out.print("\n" + str + " est un nom, ");
            }
        }
        System.out.println();
    }   
}
