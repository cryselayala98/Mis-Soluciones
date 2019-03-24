#include <bits/stdc++.h>
using namespace std;

//http://trainingcenter.ufps.edu.co/problemas/185/detalle/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int t; cin>>t;
	int n,a;
	while(t--){
		int mi=10000000, ma=0;
		cin>>n;
		while(n--){
			cin>>a;
			if(a<mi)mi =a;
			if(a>ma)ma =a;
		}
		cout<<ma-mi<<endl;
	}
	return 0;
}