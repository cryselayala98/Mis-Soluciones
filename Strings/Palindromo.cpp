#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/113/detalle/es

int main() {
	int t; cin>>t; string a;
	getline(cin,a);
	while(t--){
		getline(cin,a);
		string n="", inv="";
		for(auto x:a)
			if((x>='A' && x<='Z') || (x>='a' && x<='z') || (x>='0' && x<='9')) n+=tolower(x);
		inv = n; reverse(inv.begin(), inv.end());
		if(n==inv)cout<<"Palindromo"<<endl;
		else cout<<"No Palindromo"<<endl;
	}
	return 0;
}
