import java.io.PrintWriter;
import java.util.Scanner;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1091*/
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter am= new PrintWriter(System.out);
        int consultas=sc.nextInt();
        
        while(consultas!=0){
            int n=sc.nextInt();
            int m=sc.nextInt();
            
            int a =0;
            while(a<consultas){
                int x=sc.nextInt();
                int y=sc.nextInt();
                
                
                //averiguar la coordenada
                if (x<n && y>m) {
                    am.println("NO");
                }else if (x>n && y>m) {
                    am.println("NE");
                }else if(x>n &&y<m){
                    am.println("SE");
                    
                }else if(x<n && y<m){
                    am.println("SO");
                }else{
                    am.println("divisa");
                }
                
                
                
                a++;
            }am.flush();
            
            
            consultas=sc.nextInt();
        }
    }
    
}