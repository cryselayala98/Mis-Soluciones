import java.util.Scanner;
import java.io.IOException;
import java.io.PrintWriter;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1069*/

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
      
        
        Scanner sc = new Scanner (System.in);
        PrintWriter m = new PrintWriter(System.out);
        int a = sc.nextInt();
        
        int b =0;
        
        while(b<a){
         String c = sc.next();
         
         char [] d = c.toCharArray();
         
         
         int cont =0;
         int abierto =0;
        
         
            for (char e : d) {
                if (e==60) {//abierto
                    abierto++;
                }else if(e==62){//cerrado
                    if (abierto >0) {
                        abierto--;
                        cont++;
                        
                    }else{//abierto<=0
 }
                    
                }
                
                
            }
            m.println(cont);
            
            
            
            b++;
        }m.flush();
        
        
    }
    
}