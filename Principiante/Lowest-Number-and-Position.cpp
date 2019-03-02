#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1180*/


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int casos,v, men, pos;
   
   
   cin >> casos;
   casos--;
   cin>>v;
   men=v;
   pos=0;
   int i=1;
   while(casos--){
   	cin>>v;
   	if(v<men){
   	men=v;
   	pos=i;
   	}
   i++;
   	
   }
   cout<<"Menor valor: "<<men<<"\nPosicao: "<<pos<<"\n";
    return 0;
}