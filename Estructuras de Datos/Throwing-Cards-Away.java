import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1110*/

public class Main{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
    
        while(sc.hasNext()){
      int n=sc.nextInt();
      while(n!=0){
         
          
          int a =1;
          String cartasDesc= "Discarded cards:";
          String cartasobrante="Remaining card:";
          
          Queue cartas = new LinkedList();
          
          
          //llenar cola
          while(a<=n){
              cartas.add(a);
              a++;
          }
          
          //
          int d= n--;
          while(!cartas.isEmpty()){
              cartasDesc+=" "+cartas.poll();
              if (!cartas.isEmpty()) {
              cartas.add(cartas.poll());
              }
              if (cartas.size()>1) {
                  cartasDesc+=",";
              }else if(cartas.size()==1 && n!=1){
                cartasobrante+=" "+cartas.poll();  
              }
          }
          
          System.out.println(cartasDesc);
          System.out.println(cartasobrante);
         n=sc.nextInt();
      }     
          
          
      break;    
      }
    }
}