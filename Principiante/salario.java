import java.util.Scanner;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1008*/
public class Main {

    
    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        
          int numero= sc.nextInt();
          int horasT= sc.nextInt();
          float entre =sc.nextFloat();
          
          float sfinal= (horasT)*(entre);
          
          System.out.print("NUMBER = "+numero+"\n"
                  + "SALARY = U$ ");
          System.out.printf("%.2f", sfinal);
          System.out.println("");
    }
    
}