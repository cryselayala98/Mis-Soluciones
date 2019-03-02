import java.io.PrintWriter;
import java.util.Scanner;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1151*/

public class Main {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        PrintWriter pr = new PrintWriter(System.out);
        String cad = "";
        
        int a = sc.nextInt();
        
        int[] b = new int[a];
        
        for (int i = 0; i < b.length; i++) {
            
            if (i > 1) {
                
                b[i] = b[i - 1] + b[i - 2];                
                if (i == b.length - 1) {
                    cad += b[i];
                } else {
                    cad += b[i] + " ";
                }
                
            } else {
                b[i] = i;
                cad += b[i] + " ";
                
            }
            
        }
        
        pr.println(cad);
        pr.flush();
        
    }
    
}