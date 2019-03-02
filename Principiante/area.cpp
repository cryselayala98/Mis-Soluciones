#include <bits/stdc++.h>
 
using namespace std;

#define pi 3.14159
 /*https://www.urionlinejudge.com.br/judge/es/problems/view/1012*/
int main() {
     
   double a, b, c;
  scanf("%lf",&a);
  scanf("%lf",&b);
  scanf("%lf",&c);
      
   
   printf("TRIANGULO: %.3f\n",((a*c)/2));
   printf("CIRCULO: %.3f\n", pi*(c*c));
   printf("TRAPEZIO: %.3f\n", c*((a+b)/2));
   printf("QUADRADO: %.3f\n", b*b);
   printf("RETANGULO: %.3f\n",a*b);
   
 
    return 0;
}