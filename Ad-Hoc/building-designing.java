import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1361*/

    public static void main(String[] args) {
       Scanner sc = new Scanner (System.in);
       
       int casos = sc.nextInt();
       
       int cont =0;
       
       while (cont<casos){
           int pisos = sc.nextInt();
           
           TreeMap <Integer, Integer> edificio = new TreeMap <Integer, Integer>();
           
           int cont2=0;
           while(cont2<pisos){
               int añadirPiso= sc.nextInt();
               int color  = 1;      //neg=rojo:false; pos=azul:true
               if (añadirPiso<0) {
                   color=0;
               }
               edificio.put(Math.abs(añadirPiso), color);
               cont2++;
        
           }
            int pisosAcept=1;
            boolean flag=false;
           while(edificio.size()>1 ){
               int piso1=edificio.firstKey();
               int color=edificio.get(piso1);
               edificio.remove(piso1);
               
               int piso2=edificio.firstKey();
               int color2=edificio.get(piso2);
               
               if (color!=color2) {
                   pisosAcept++;
                   if (!flag) {
                        flag=true;
                   }
               }else{
                   flag=false;
               }
               
           }
           if (pisosAcept==0) {
               pisosAcept++;
           }
           System.out.println(pisosAcept);
           cont++;
           
       }
    }
    
}