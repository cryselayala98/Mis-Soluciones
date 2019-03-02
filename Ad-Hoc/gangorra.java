import java.util.ArrayList;
import java.util.Scanner;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/2455*/

public class Main {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int P1=sc.nextInt(); 
        int C1=sc.nextInt(); 
        int P2 =sc.nextInt(); 
        int C2=sc.nextInt();
        int i= P1 * C1 ;
        int j=P2 * C2;
        if(i==j){
            System.out.println(0);
        }else if(i<j){
            System.out.println(1);
        }else{
            System.out.println(-1);
        }


    }
    
}