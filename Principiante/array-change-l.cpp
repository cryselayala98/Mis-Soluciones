#include <bits/stdc++.h>
 
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1175*/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
     int array[20];
     
     int num;
     int k=20;
     while(k--){
     	cin>>num;
     	array [k]=num;
     }
     k=0;
     for(k; k<20; k++){
     	cout<<"N["<<k<<"] = " <<array[k]<<"\n";
     }
    return 0;
}