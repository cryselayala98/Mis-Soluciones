import java.util.Scanner;


/*https://www.urionlinejudge.com.br/judge/es/problems/view/1060*/
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)  {

        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
        int pos=0;
            for (int i = 0; i < 6; i++) {
                double num = sc.nextDouble();
                if (num>0) {
                    pos++;
                }
            }
            System.out.println(pos+" valores positivos");
     
     

        }
    }

    
}



 
