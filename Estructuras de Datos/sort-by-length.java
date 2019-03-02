import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1244*/

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int casos = Integer.parseInt(sc.next());
        int a = 0;
        String frase = sc.nextLine();
        while (a < casos) {
             frase = sc.nextLine();

          String [] ss= frase.split(" ");
            ArrayList<String> palabras = new ArrayList<>();
            ArrayList<Integer> tamaños = new ArrayList<>();

           
            for (String palabra: ss) {
                 int size = palabra.length();
                tamaños.add(size);
                palabras.add(palabra);
            }

            Collections.sort(tamaños, Collections.reverseOrder());
            boolean flag = false;
            String ord = "";
            for (Integer tamaño : tamaños) {
                for (String palabra2 : palabras) {
                    if (palabra2.length() == tamaño) {
                        if (!flag) {
                            flag = true;
                            ord += palabra2;
                            palabras.remove(palabra2);
                            break;
                        } else {
                            ord += " " + palabra2;
                            palabras.remove(palabra2);
                            break;
                        }

                    }

                }

            }
            System.out.println(ord);
            a++;
        }
    }

}