
import java.io.PrintWriter;
import java.util.Scanner;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1068*/
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // 1068
        
        Scanner sc = new Scanner (System.in);
        
        while (sc.hasNext()) {            
            String cadena = sc.next();
           
            
            char [] caracteres = cadena.toCharArray();
            
            int abre =0;
            int cierra=0;
            boolean validacion =false;
            
            for (char caractere : caracteres) {
               
                
                if (caractere==40) {
                    abre++;
                }else if (caractere==41 ){
                    if(abre>0){
                  abre--; 
//                    cierra++;
 }else{
                           
  validacion =true; break;       
                    }
        }   
    }  
            
            if (abre==cierra && !validacion) {
                System.out.println("correct");
            }else{
                System.out.println("incorrect");
            }
            
            
            
            
        }
    }
    
}