#include <bits/stdc++.h>
using namespace std;

/*http://trainingcenter.ufps.edu.co/#/problemas/5/detalle/es*/


int main() {
	// your code goes here
int c;
cin>>c;
int a;
while(c--) {

cin>>a;
bool k=false; int i =2;

if(a==1) k=true;
while(i<=10){
if(k)break;

if( a%i==0 && a>=  i*i  ) {k=true; break;} 

i++;}

if (k) cout<<"el valor estaba marcado"<<endl;
else cout<<"el valor no estaba marcado" <<endl;
} 
	return 0;
}