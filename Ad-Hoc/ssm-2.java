/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.Scanner;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1786*/

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
     
        while(sc.hasNext()){
            String cad= sc.next();
            int resto1=0, resto2=0;
            int j=cad.length()-1;
            for(int i=0;i<cad.length(); i++ ){
                int abajo=(int) cad.charAt(i)-48;
               
                resto1+= abajo* (i+1);
                resto2+= abajo* (j+1);
                j--;
            }
            resto1=resto1%11;
            if(resto1==10){resto1=0;}
            resto2=resto2%11;
             if(resto2==10){resto2=0;}
            System.out.println(cad.substring(0, 3)+"."+cad.substring(3,6)+"."+cad.substring(6 , 9)+"-"+resto1+""+resto2);
            
        }
        
    }
    
}