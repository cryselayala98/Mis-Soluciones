import java.io.PrintWriter;
import java.util.Scanner;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1174*/
public class Main {

        public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);
        PrintWriter num = new PrintWriter(System.out);
        
        float [] vector = new float[100];
        for (int f = 0; f<vector.length; f++) {
            vector [f]=sc.nextFloat();
            
            if (vector [f]<= 10 ) {
                num.print("A["+f+"] = " );
                double pos = vector [f];
                pos =pos*10;
               pos=Math.round(pos);
               num.print(pos/10);
//                num.printf("%2f", pos);
              num.print("\n");
            }
            
        }num.flush();
        
            
        }
    
}