/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

import java.util.Scanner;
import java.util.Stack;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1340*/

    public static void main(String[] args) {
      Scanner sc = new Scanner (System.in);
      
      while(sc.hasNext()){
          int dimension =sc.nextInt();
 
          int a =0;
          Queue<Integer> cola  = new LinkedList<Integer>();
          Stack<Integer> pila = new Stack<Integer>();
          ArrayList<Integer> colaPrioridad = new  ArrayList<Integer>();
           
           boolean ccola=true;
           boolean ppila=true;
           boolean ccolaPrioridad=true;
           
          while(a<dimension){
              
              int comando =sc.nextInt();
              int num=sc.nextInt();
              
            
              if (comando==1) {
                  colaPrioridad.add(num);
                  cola.add(num);
                  pila.push(num);
              }else if (comando==2) {
               
                    /*detectando priority queue*/
                  Comparator<Integer> comparador = Collections.reverseOrder();
                Collections.sort(colaPrioridad, comparador);
                int b=colaPrioridad.remove(0);
                  if (b!=num) {
                      ccolaPrioridad=false;
                  }
   
                  /* detectando queue*/
                  int n=cola.poll();
                  if (n!=num) {
                      ccola=false;
                  }
                  //es pila?
                  int s = pila.pop();
                  if (s!=num) {
                      ppila=false;
                  }
                  
              }
   
              a++;
          }
          /*detectando mas estructuras*/
          int repeticion=0;
          if (ccola) {
              repeticion++;
          }if (ppila) {
              repeticion++;
          }if (ccolaPrioridad) {
              repeticion++;
          }
          if (repeticion>1) {
              System.out.println("not sure");
           
          }else if (ccola) {
              System.out.println("queue");
          }else if (ppila) {
              System.out.println("stack");
          }else if (ccolaPrioridad) {
              System.out.println("priority queue");
          }else{
              System.out.println("impossible");
          }
          
      }
    }
    
}