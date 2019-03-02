import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeMap;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1281*/

public class Main {

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner();

        int casos = Integer.parseInt(sc.next());
        int cont = 0;
        while (cont < casos) {
            
            TreeMap<String, Double> ListaDisponible = new TreeMap<>();
            
            int listaDisp=Integer.parseInt(sc.next());
                    int cont2=0;
                    while(cont2<listaDisp){
                        String nombre=sc.next();
                        double precio = Double.parseDouble(sc.next());
                        
                        ListaDisponible.put(nombre, precio);
                        cont2++;
                    }
                    
                    int cantidadComprar=Integer.parseInt(sc.next());
                    int cont3 =0;
                    double total=0;
                    while(cont3<cantidadComprar){
                        String nombre2=sc.next();
                        int cantidad=Integer.parseInt(sc.next()); 
                        
                        double precio2=ListaDisponible.get(nombre2);
                        total+=precio2*cantidad;
                        
                        cont3++;
                    }
                  
                    System.out.printf("R$ %.2f\n", total);

            cont++;
        }

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