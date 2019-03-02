import java.util.Scanner;
 
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1004*/
public class Main {
 
    public static void main(String[] args)  {
 
        Scanner sc= new Scanner (System.in);
        while(sc.hasNext()){
            int a=  sc.nextInt();
            int b= sc.nextInt();
            
            int prod= a*b;
            
            System.out.println("PROD = "+prod);
            
        }
    }
 
}