#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/2344*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int nota;
    cin>> nota ;
    
    char r;
    
    if(nota==0){
        r='E';
    }else if(nota>0 && nota<36){
        r='D';
    }else if(nota>35 && nota<61){
        r='C';
    }else if(nota>60 && nota<86){
        r='B';
    }else{
       
        r='A';
    
    }
    cout<< r<<endl;
    
    return 0;
    
}