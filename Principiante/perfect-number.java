import java.io.PrintWriter;
import java.util.Scanner;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1164*/

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        PrintWriter pr = new PrintWriter(System.out);

        int a = sc.nextInt();

        int c = 0;

        while (c < a) {
            int contador = 0;
            int d = sc.nextInt();

            for (int i = 1; i < d; i++) {

                if (d % i == 0) {  //i es divisible a d 

                    contador += i;

                }

            }
            if (contador == d) {
                pr.println(d + " eh perfeito");
            } else {
                pr.println(d + " nao eh perfeito");
            }
            c++;
        }
        pr.flush();
    }

}