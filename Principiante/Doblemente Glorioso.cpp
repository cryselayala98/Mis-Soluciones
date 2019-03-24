#include <bits/stdc++.h>
using namespace std;

//http://trainingcenter.ufps.edu.co/problemas/207/detalle/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int t; cin>>t; int n,a,b,acum;
	while(t--){
		cin>>n;
		acum=0;
		while(n--){
			cin>>a>>b;
			if(a>b)acum+=3;
			else if(a==b)acum+=1;
			cout<<acum<<endl;
		}
	}
	return 0;
}