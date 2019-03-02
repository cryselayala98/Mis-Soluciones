import java.util.Scanner;
//https://www.urionlinejudge.com.br/judge/en/problems/view/1387

class Main { 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int x = sc.nextInt();
            int y = sc.nextInt();
            
            if(x==0 && y ==0)break;
            
            System.out.println(x+y);
        }
        
    }
    
}