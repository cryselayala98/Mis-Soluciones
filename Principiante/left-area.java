import java.util.Scanner;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1189*/

public class Main {

        public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);
        
        String letra = sc.next();
        
        float  [] [] vector = new float [12][12]; 
        
        for (int i = 0; i < vector.length; i++) {
            for (int j = 0; j < vector.length; j++) {
            
              vector [i][j]= sc.nextFloat();                
            }
        }
        
        float contadorNum=0;
        int contadorPromedio=0;
        
        int columna =0; 
        int filaInicial = 1;
        int filaInicial2 =1;
        int filaFinal = 10;
        
        while (columna<5){
            while(filaInicial<=filaFinal) {
                contadorNum+= vector [filaInicial][columna];
                contadorPromedio++;
                filaInicial++;
            }
            
            if (filaInicial==5 && filaFinal==6 ) {
                break;
            }
            filaInicial2++;
            filaInicial=filaInicial2;
            filaFinal--;
            
            columna++;
        }
        
        if (letra.equals("S")) {
            System.out.println(contadorNum);
        }else if (letra.equals("M")) {
            float res=contadorNum/contadorPromedio; 
            System.out.printf("%.1f", res);
           
        }
    }
    
}