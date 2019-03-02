#include <iostream>
using namespace std;

int fibo [35];

void precalcular(int n){
	fibo[0]=0;
	fibo[1]=1;
	
	for(int i=2; i<=n; i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
}

int main() {
	
	
	int n;

	cin>>n;
	precalcular(n);
	
	for(int i=0; i<=n; i++){
		cout<<fibo[i]<<endl;
	}
	return 0;
}