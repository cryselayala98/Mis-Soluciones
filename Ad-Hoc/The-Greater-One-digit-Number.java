import java.util.Scanner;
//https://www.urionlinejudge.com.br/judge/es/problems/view/1867author CORE I3
 
public class Main { 

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {

            String x = sc.next();
            String y = sc.next();

            if (x.equals("0") && y.equals("0")) {
                break;
            }
            int a = sumaDigitos(x);
            int b = sumaDigitos(y);
            if (a == b) {
                System.out.println(0);
            } else if (a > b) {
                System.out.println(1);
            } else {
                System.out.println(2);
            }
        }
    }

    static int sumaDigitos(String a) {

        int suma = 0;
        for (int i = 0; i < a.length(); i++) {
            int val = a.charAt(i) - 48;
            suma += val;
        }

        if (suma > 9) { 
            suma = sumaDigitos("" + suma);
        }
        return suma;

    }
}