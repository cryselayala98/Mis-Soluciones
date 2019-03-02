
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.TreeSet;
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=&page=show_problem&problem=2003
class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner();
        TreeSet<String> palabras = new TreeSet<>();
        ArrayList<String> lala = new ArrayList<>();

        while (sc.hasNext()) {
            String cad = sc.nextLine();
            if (!cad.equals("")) {
                lala.add(cad);
            }
        }

        String union = "";

        for (int z = 0; z < lala.size(); z++) {

            String cadaux = lala.get(z);

            for (int j = 0; j < cadaux.length(); j++) {

                char aux = cadaux.charAt(j);

                if (aux >= 65 && aux <= 90) {
                    aux += 32; 

                }
                if (aux >= 97 && aux <= 122) {
                    union = union + aux;
                    if (j == cadaux.length() - 1) {
                        palabras.add(union);
                        union = "";

                    }

                }
                if (aux < 97 || aux > 122) {
                    
                    
                        palabras.add(union);
                        union = "";
                    
                }
            }

        }
        Iterator<String> itr = palabras.iterator();
        while (itr.hasNext()) {
            String c = itr.next();
            if (!c.equals("")) {
                System.out.println(c);
            }

        } //System.out.println();

    }

    static class Scanner {

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");
        int espacios = 0;

        public String nextLine() throws IOException {
            if (espacios > 0) {
                espacios--;
                return "";
            } else if (st.hasMoreTokens()) {
                StringBuilder salida = new StringBuilder();
                while (st.hasMoreTokens()) {
                    salida.append(st.nextToken());
                    if (st.countTokens() > 0) {
                        salida.append(" ");
                    }
                }
                return salida.toString();
            }
            return br.readLine();
        }

        public String next() throws IOException {
            espacios = 0;
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public boolean hasNext() throws IOException {
            while (!st.hasMoreTokens()) {
                String linea = br.readLine();
                if (linea == null) {
                    return false;
                }
                if (linea.equals("")) {
                    espacios++;
                }
                st = new StringTokenizer(linea);
            }
            return true;
        }
    }
}