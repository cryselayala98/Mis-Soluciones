import java.util.Scanner;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1005*/
public class Main {

    
    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        
                    
            
           float a = sc.nextFloat();
           float b = sc.nextFloat();
     
           
           float n = ((a*3.5f)+(b*7.5f))/11;
           
            System.out.print("MEDIA = ");
           System.out.printf("%.5f", n);
            System.out.println("");

         
        }
    }
    