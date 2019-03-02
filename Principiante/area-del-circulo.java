
import java.util.Scanner;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1002*/

public class Main {

    public static void main(String[] args)  {

        Scanner sc = new Scanner(System.in);
       while( sc.hasNext()) {
        
        double pi= 3.14159;
        
        double R = sc.nextDouble();
        
        double A= pi*Math.pow(R, 2);
        
           System.out.print("A=");
           System.out.printf("%.4f", A);
           System.out.println("");
                }
        
        
        
        
    }

}