import java.util.Scanner;
//https://www.urionlinejudge.com.br/judge/es/problems/view/2126

public class Main { 

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int caso = 1;
        while (sc.hasNext()) {
            String sub = sc.next();
            String cadenota = sc.next();
            int posicionEmpezo = 0;
            int cantSub = 0;
            char inisub = sub.charAt(0);
            for (int i = 0; i < cadenota.length(); i++) {
                if (cadenota.charAt(i) == inisub) {
                    boolean v = validarSub(sub, cadenota, i, i + sub.length());
                    if (v) {
                        posicionEmpezo = i + 1;
                        cantSub++;
                        i += sub.length() - 1;
                    }

                }
            }
            System.out.println("Caso #" + caso + ":");
            caso++;
            if (cantSub > 0) {

                System.out.println("Qtd.Subsequencias: " + cantSub);
                System.out.println("Pos: " + posicionEmpezo);
            } else {
                System.out.println("Nao existe subsequencia");
            }
            System.out.println();
        }

    }

    static boolean validarSub(String sub, String cadenota, int ini, int fin) {
        if (fin > cadenota.length()) {
            return false;
        }
        String validacion = cadenota.substring(ini, fin);
        return (sub.equals(validacion));
    }
}