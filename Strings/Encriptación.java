import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//https://www.urionlinejudge.com.br/judge/es/problems/view/1024

public class Main {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner();

        int n=  Integer.parseInt(sc.next());
        int aux;
        while(n > 0){  //recorre cada caso de prueba
  
            String cadena= sc.nextLine();
            
            
            char [] palabra1 = cadena.toCharArray();//un vector de char lleno con la palabra
            
            for (int i = 0; i < palabra1.length; i++) {
                aux=palabra1[i];
                if((aux>=65 && aux<=90)||(aux>=97 && aux<=122) ){//voy aca comparar cada caracter si es mayuscula o minuscula en el cod ascii
                palabra1[i]+=3;//el valor del caracter aumenta en 3
                }
                
                
               
   
            }
//             
//          revertir
      char [] palabra2= new char [palabra1.length];//
     
     int pos=palabra1.length-1;//
     
     char a;
     int b =0;
      
     while(b<palabra1.length && pos>=0){
        a=palabra1[pos];
         palabra2[b]= a;
      
          b++;
          pos--;
     }
     

     int media= palabra2.length/2;
            
            for (int k = media; k < palabra2.length; k++) {
                palabra2[k] -=1;
            }
            
            //mostrar la cadena unida
            String cad="";
            
            for (int h = 0; h < palabra2.length; h++) {
                cad+=palabra2[h];
            }
            System.out.println(cad);
  n--;
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

        //public tipo nextTipoDato() throws IOException {
        //	return Tipo.parseTipo(next());
        //}
    }
}
