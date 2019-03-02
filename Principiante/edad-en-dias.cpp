#include <bits/stdc++.h>
 
using namespace std;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1020*/
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
      int a;
	  cin>>a;
  
 int resto= (a/365);
 a = a-(365*resto);
 cout<< resto << " ano(s)\n";
 
 resto= (a/30);
 a = a- (30*resto);
 cout<< resto << " mes(es)\n";
 
 cout<<a<<" dia(s)\n";
    

   
 
    return 0;
}