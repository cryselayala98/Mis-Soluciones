import java.util.Scanner;
import java.util.TreeMap;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1865*/

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        
        int casos=sc.nextInt();
        int a =0;
        while(a<casos){
            String heroe=sc.next();
            int value=sc.nextInt();
            if (heroe.equalsIgnoreCase("Thor")) {
                System.out.println("Y");
            }else{
                System.out.println("N");
            }
            
            
            a++;
        }
           
    }
    
}