import java.io.IOException;

import java.io.PrintWriter;
import java.util.Scanner;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1021*/
public class Main {

    public static void main(String[] args)throws IOException {

        Scanner sc = new Scanner(System.in);

        if (sc.hasNext()) {
            
        

            float a =  Float.parseFloat(sc.nextLine());
            a *=100 ;
            int moncount = 1;
            int count = 0;
            int moneda = 10000;
            PrintWriter ac = new PrintWriter(System.out);
            ac.println("NOTAS:");
            while (moneda >= 1) {

                while ((a - moneda) >= 0) {
                    count++;
                    a = (int) (a - moneda);

                }

                if (moneda >= 200) {
                    ac.print(count + " nota(s) de R$ ");
                    float m=moneda/100;
                    ac.printf("%.2f", m);
                    ac.println();
                }
                if (moneda < 200) {

                    if (moneda == 100) {
                        ac.println("MOEDAS:");

                    }

                    ac.print(count + " moeda(s) de R$ ");
                    float m =moneda;
                    ac.printf("%.2f", m/100);
                    ac.println();
                }

                if (moneda == 5000) {
                    moneda = 2000;
                } else if (moneda == 500) {
                    moneda = (int) 200;
                } else if (moneda == 25) {
                    moneda = (int) 10;
                } else if (moneda == 5) {
                    moneda = (int) 1;
                } else {
                    moneda = moneda / 2;
                }

                count = 0;
            }

            ac.flush();
        }
    }
    
    }



