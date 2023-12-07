import java.util.Scanner;
import java.util.InputMismatchException;

public class TestSleep {

    public static void main(String[] args) throws InterruptedException {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Veuillez saisir le nombre de secondes : ");

        try{

            int i = scanner.nextInt();
        
            System.out.println("Attente de " + i + " Secondes");

            Thread.sleep(i*1000);

        }catch (InputMismatchException e){
            System.out.println("le nombre est mal formé... ");
        }

        scanner.close();
    }
}