import java.util.Scanner;
//https://www.urionlinejudge.com.br/judge/en/problems/view/2062@author CORE I3
 
public class Main { 

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
      
            int size = sc.nextInt();

            String r = "";
            while (size > 0) {
                String a = sc.next();
                String b = "";
                if (a.length() == 3) {
                    if (a.charAt(0) == 'O' && a.charAt(1) == 'B') {
                        a = "OBI";
                    } else if (a.charAt(0) == 'U' && a.charAt(1) == 'R') {
                        a = "URI";
                    }
                }

                if (size > 1) {
                    r += a + " ";
                } else {
                    r += a;
                }
                size--;
            }
            System.out.println(r);
        }
    }
