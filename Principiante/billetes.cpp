#include <bits/stdc++.h>
using namespace std;

//https://www.urionlinejudge.com.br/judge/es/problems/view/1018

int main(){
int n;

cin >>n;
cout<<n<<endl;
int a=n/100;
n=n - (100*a);


cout<<a<<" nota(s) de R$ 100,00"<<endl;


a=n/50;
n=n - (50*a);

cout<<a<<" nota(s) de R$ 50,00"<<endl;

a=n/20;
n=n - (20*a);

cout<<a<<" nota(s) de R$ 20,00"<<endl;

a=n/10;
n=n - (10*a);

cout<<a<<" nota(s) de R$ 10,00"<<endl;

a=n/5;
n=n - (5*a);

cout<<a<<" nota(s) de R$ 5,00"<<endl;

a=n/2;
n=n - (2*a);

cout<<a<<" nota(s) de R$ 2,00"<<endl;

a=n/1;
n=n - (1*a);

cout<<a<<" nota(s) de R$ 1,00"<<endl;


return 0;
}


