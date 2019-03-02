import java.util.Scanner;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1858*/

public class Main {    
    
    public static void main(String[] args) {
        
    
    Scanner sc = new Scanner(System.in) ;
    
    while(sc.hasNext()){
    
        int a = sc.nextInt();
        
        int posicion =1;
        int res=1;
        
        int b=0;//pos1
        int c =0;//pos2
        int menor=Integer.MAX_VALUE;
        
        for (int i = 0; i < a; i++) {
            b= sc.nextInt();
            
            if (b==menor) {
               
            }else if(b<menor){
                res=posicion;
                menor=b;
            }
            c=b;
            posicion++;
        }
        
        System.out.println(res);
}
    
        
    }
       
    
}