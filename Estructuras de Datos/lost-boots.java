import java.util.Scanner;
import java.util.TreeMap;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1245*/
public class Main {
      public static void main(String[] args) {
       
        Scanner sc = new Scanner (System.in);
        
        while (sc.hasNext()) {   
            
            TreeMap <Integer, Integer> derecho= new TreeMap<>(); 
            TreeMap <Integer, Integer> izquierdo= new TreeMap<>();
             int casos= sc.nextInt();
            int cont =0;
            while(cont<casos){
                
                int talla= sc.nextInt();//clave treemap
                String ladoZapato = sc.next();
                
                if (ladoZapato.equals("D")) {//derecho
                    if (derecho.containsKey(talla)) {
                        int cantTalla= derecho.get(talla);
                        derecho.remove(talla);
                        derecho.put(talla, cantTalla+1);
                    }else{
                        derecho.put(talla, 1);
                        
                    }
                    
                }else   if (ladoZapato.equals("E")) {
                    if (izquierdo.containsKey(talla)) {
                        int cantTalla= izquierdo.get(talla);
                        izquierdo.remove(talla);
                        izquierdo.put(talla, cantTalla+1);
                    }else{
                        izquierdo.put(talla, 1);
                        
                    }
                    
                }
         cont++;
            }int countRep=0;
              while (!derecho.isEmpty()) {
              int claveBusqueda = derecho.firstKey();
                  if (izquierdo.containsKey(claveBusqueda)) {
                     
                      int izq=izquierdo.get(claveBusqueda);
                      int der=derecho.get(claveBusqueda);
                      while (izq>0 && der>0 ) {
                          izq--; der--; countRep++;
                      }
                      
                  }
              
              
              derecho.remove(claveBusqueda);
              }
              System.out.println(countRep);
        }
    }
    
}