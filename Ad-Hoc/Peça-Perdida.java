import java.util.ArrayList;
import java.util.Scanner;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/2322*/

public class Main {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int l= sc.nextInt();
        int total= l*(l+1)/(2);
        for (int i = 1;  i< l; i++) {
            int n= sc.nextInt();
           total-=n;
           
        }
        System.out.println(total);
    }
    
}