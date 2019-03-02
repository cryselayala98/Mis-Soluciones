import java.io.PrintWriter;
import java.util.Scanner;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1080*/

public class Main {

    public static void main(String[] args) {//1164
       
        Scanner sc = new Scanner(System.in);

        PrintWriter pr = new PrintWriter(System.out);
        
        int [] a = new int[100];
        
        for (int i=0; i < a.length; i++) { //llenar
            
            a[i]= sc.nextInt();
  }
        
        int may=0;
        int posicion = 0;
        
        for (int i = 0; i < a.length; i++) {
            
            if (a[i]>may) {
             may=a[i];    
            posicion=i+1;
            }
        }        
        
      pr.println(may);
      pr.println(posicion);
        
//
//        
        
        pr.flush();
    }
    }
