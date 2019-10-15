#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/208/detalle/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int c; cin>>c;
	
	while(c--){
		int a=0, b=0;
		int n ; cin>>n;
		int num[n];
		for(int i = 0; i< n; i++){
			int y; cin>>y;
			num[i]=y;
			if(i< n/2) a+=y;
			else b+= y;
		}
		if(a<=b)cout<<"Orden original";
		else{
			cout<<"Orden invertido";
			reverse(num, num+n);
		}
		for(int i = 0; i<n; i++)cout<<" "<<num[i];
		cout<<endl;
	}
	return 0;
}
