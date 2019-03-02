import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.StringTokenizer;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1009*/

/**
 *
 * @author CORE I3
 */
public class Main {//ejerc 1009
  
    public static void main(String[] args) throws IOException {
        
    
    Scanner sc = new Scanner ();
    
    while (sc.hasNext()){
    
        String nombre= sc.next();

        
       double sueldo=Double.parseDouble( sc.nextLine());
        double ganancias=Double.parseDouble( sc.nextLine());
        
        double total=  (((ganancias * 15)/100)+sueldo);
        
        System.out.print("TOTAL = R$ ");
        System.out.printf("%.2f", total);
        System.out.println("");

}
    
        
    }
    
     static class Scanner {

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");
        int espacios = 0;

        public String nextLine() throws IOException {
            if (espacios > 0) {
                espacios--;
                return "";
            } else if (st.hasMoreTokens()) {
                StringBuilder salida = new StringBuilder();
                while (st.hasMoreTokens()) {
                    salida.append(st.nextToken());
                    if (st.countTokens() > 0) {
                        salida.append(" ");
                    }
                }
                return salida.toString();
            }
            return br.readLine();
        }

        public String next() throws IOException {
            espacios = 0;
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public boolean hasNext() throws IOException {
            while (!st.hasMoreTokens()) {
                String linea = br.readLine();
                if (linea == null) {
                    return false;
                }
                if (linea.equals("")) {
                    espacios++;
                }
                st = new StringTokenizer(linea);
            }
            return true;
        }
    
}
     
         
     }