import java.util.Scanner;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1555*/

public class Main {
     public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int casos=sc.nextInt();
        int a =0;
        while(a<casos){
            int x=sc.nextInt();
            int y = sc.nextInt();
            
            int fRafael=(int) Math.pow((3*x),2)  +  (int) Math.pow(y, 2);
            int fBeto=2*(int) Math.pow(x,2)+ (int) Math.pow((5*y),2);
            int fCarlos=-100*x+  (int) Math.pow(y, 3);
            
            int a1=fRafael;
            int a2=fBeto;
            int a3=fCarlos;
            
            int mayor= ordenarMenorMayor(a1, a2, a3, 0);
            
            if (mayor==fRafael) {
                System.out.println("Rafael ganhou");
            }else if (mayor==fBeto) {
                System.out.println("Beto ganhou");
            }else if (mayor==fCarlos) {
                System.out.println("Carlos ganhou");
            }
            a++;
        }
     }
     public static int ordenarMenorMayor(int a, int b, int c, int d) {
        int menor = 0;
        int mayor = 0;
        int aux = 0;
        if (a >= b) {
            aux = b;
            b = a;
            a = aux;
        }

        if (a >= c) {
            aux = c;
            c = a;
            a = aux;
        }

        if (a >= d) {
            aux = d;
            d = a;
            a = aux;
        }

        if (b >= c) {
            aux = c;
            c = b;
            b = aux;
        }

        if (b >= d) {
            aux = d;
            d = b;
            b = aux;
        }

        if (c >= d) {
            aux = d;
            d = c;
            c = aux;
        }
        mayor = d;

      return mayor;

    }
}