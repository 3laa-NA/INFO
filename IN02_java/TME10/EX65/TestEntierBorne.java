public class TestEntierBorne {
    public static void main(String[] args) {
        
        int i1 = (int)(Math.random()*301 - 150);
        int i2 = (int)(Math.random()*3);
        
        System.out.println("pour ebX : " + i1);
        System.out.println("pour ebY : " + i2);
        System.out.println("somme" + (i1+i2));
        
        try{
        
        EntierBorne ebX = new EntierBorne(i1);
        EntierBorne ebY = new EntierBorne(i2);
        EntierBorne som = ebX.somme(ebY);
        EntierBorne div = ebX.divPar(ebY);
        

        }catch(HorsBornesException e){
            System.out.println(e.getMessage());
        }catch(DivisionParZeroException e){
            System.out.println(e.getMessage());
        }
        
    }
}
