import java.util.Scanner;
//https://www.urionlinejudge.com.br/judge/en/problems/view/2232

public class Main {     
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int casos = sc.nextInt();
        while(casos>0){
            int n= sc.nextInt();
            int i=1;
            int sumaPascal=1; 
            while(i<n){
                sumaPascal= (int) (sumaPascal+Math.pow(2, i));
                i++;
            }
            System.out.println(sumaPascal);
            casos--;
        }
    }
    
}