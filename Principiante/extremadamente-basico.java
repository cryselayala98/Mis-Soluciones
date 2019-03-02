import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * https://www.urionlinejudge.com.br/judge/es/problems/view/1001
 */
public class Main {

    
    public static void main(String[] args) throws IOException {
      
        Scanner sc = new Scanner();
        
        while (sc.hasNext()) {            
            
            int A = Integer.parseInt(sc.next());
            int B = Integer.parseInt(sc.next());
            
            int X = A+B;
            
            System.out.println("X = "+X);
        }
    }
    
    static class Scanner{
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");
        int espacios = 0;

        public String nextLine() throws IOException{
        	if(espacios>0){
            	espacios--;
            	return "";
            }else if(st.hasMoreTokens()){
                StringBuilder salida = new StringBuilder();
                while(st.hasMoreTokens()){
                    salida.append(st.nextToken());
                    if(st.countTokens()>0){
                        salida.append(" ");
                    }
                }
                return salida.toString();
            }
            return br.readLine();
        }

        public String next() throws IOException{
        	espacios=0;
            while (!st.hasMoreTokens() ) {
                st = new StringTokenizer(br.readLine() );
            }
            return st.nextToken();
        }

        public boolean hasNext() throws IOException{
            while (!st.hasMoreTokens()) {
                String linea = br.readLine();
                if (linea == null) {
                    return false;
                }
                if(linea.equals("")){
                	espacios++;
                }
                st = new StringTokenizer(linea);
            }
            return true;
        }

         //public tipo nextTipoDato() throws IOException {
         //	return Tipo.parseTipo(next());
         //}
    }
}