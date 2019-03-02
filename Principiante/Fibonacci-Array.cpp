#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1176*/

long long fibo[65];

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
fibo[0]=0;
fibo [1]=1;
int index_fibo_mas_alto=1;
int casos;
cin>>casos;
int num;
while(casos--){

cin>>num;
if(num>index_fibo_mas_alto){
    for(int i= index_fibo_mas_alto+1; i<=num; i++){
            fibo[i]=fibo[i-1]+fibo[i-2];
    }
    index_fibo_mas_alto=num;
}
cout<<"Fib("<<num<<") = "<<fibo[num]<<endl;


}

return 0;
}