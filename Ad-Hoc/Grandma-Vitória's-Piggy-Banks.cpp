#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/2247*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int depositos , i, j;
    
    cin>>depositos;
    int y=1;
    while(depositos!=0){
        cout<< "Teste "<<y<<"\n";
        int t=0;
        int k=0;
        
        while(depositos-->0){
            cin>>i>>j;
            t+=i;
            k+=j;
            int u=t-k;
            cout<<u<<"\n";
        }
        cout<<endl;
        y++;
        cin>>depositos;
    }
    
    return 0;
}