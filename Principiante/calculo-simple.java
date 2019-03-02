
import java.io.PrintWriter;
import java.util.Scanner;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1010*/
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        PrintWriter am = new PrintWriter(System.out);

        while (sc.hasNext()) {
            int codigo1 = sc.nextInt();
            int cant1 = sc.nextInt();
            float precio1 = sc.nextFloat();

            int codigo2 = sc.nextInt();
            int cant2 = sc.nextInt();
            float precio2 = sc.nextFloat();

            float suma1 = precio1 * cant1;
            float suma2 = precio2 * cant2;

            float total = suma1 + suma2;
            am.printf("VALOR A PAGAR: R$ %.2f%n", total);
            am.flush();
        }
    }

}