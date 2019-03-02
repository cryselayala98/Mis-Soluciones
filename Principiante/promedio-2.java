import java.util.Scanner;


/*https://www.urionlinejudge.com.br/judge/es/problems/view/1006*/
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)  {

        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
        
    float a =  sc.nextFloat();
    float b =  sc.nextFloat();
    float c =  sc.nextFloat();
     
     
     float media1=  ((a* 2)/10);
     float media2=  ((b* 3)/10);
     float media3=  ((c* 5)/10);
     
     float mediat= (media1+media2+media3);
     
     System.out.print("MEDIA = ");
     System.out.printf("%.1f", mediat);
     System.out.print("\n");
            

        }
    }

    
}



 
