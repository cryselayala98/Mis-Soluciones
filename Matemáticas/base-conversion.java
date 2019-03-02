import java.io.PrintWriter;
import java.util.Scanner;

/* https://www.urionlinejudge.com.br/judge/es/problems/view/1193*/

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        PrintWriter am = new PrintWriter(System.out);
        
        int casos =sc.nextInt();
        int i =0;
        int casoss=1;
        while (i<casos){
            
            String caso1=sc.next();
            String caso=sc.next();
          
           
          
           int categoria=0;
            if (caso.equalsIgnoreCase("dec")) {
                categoria=1;
            }else if (caso.equalsIgnoreCase("hex")) {
                categoria=2;
            }else if (caso.equalsIgnoreCase("bin")) {
                categoria=3;
            }
            
            String ress =conversion(caso1, categoria);
            String res="Case "+casoss+":";
            res=res+ress;
            am.println(res+"\n");
            
            i++;casoss++;
        }am.flush();
    }
    
    public static String conversion (String n, int categoria){
        String res="";
        
        if (categoria==1) {//dec
            //dec a hex
            int a =Integer.parseInt(n);
            String hex = Integer.toHexString(a);
            res+="\n"+hex+" hex";
            //dec a bin
            //uso int a
            String binario = Integer.toBinaryString(a);
            res+="\n"+binario+" bin";
            return res;
        }
        
        if (categoria==2) {//hex
            
            String cad2="";
            //hex a bin
           int a=Integer.parseInt(n, 16);
           String binary = Integer.toBinaryString(a);
            cad2+="\n"+binary+" bin";
            
            //bin a dec
            //uso binary
            int num=Integer.parseInt(binary,2);
            res+="\n"+num+" dec";
            res+=cad2;
            return res;
        }
        
        if (categoria==3) {//binario
            //de bin a dec
            //uso n
             int num=Integer.parseInt(n,2);
            res+="\n"+num+" dec";
            //de dec a hex
            //uso num
              String str = Integer.toHexString(num);
              res+="\n"+str+" hex";
            
            return res;
        }
        
        
        
        return res;
    }
}