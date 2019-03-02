#include <bits/stdc++.h>
using namespace std;

https://codeforces.com/gym/101972/problem/K


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int c,n; string a,b;
	cin>>c;
	while(c--){
		cin>>n>>a>>b;
		string aa="", bb="";
		for(int i =0; i<n; i++){
			if(a[i]!=b[i])aa+=a[i], bb+=b[i];
		}
		//hacer rotacion
		string aux= aa;
		for(int i=0; i< aa.size(); i++){
			int rot = (i+aa.size()-1)%aa.size();
			aux[rot] = aa[i];
		}
		if(aux==bb)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	return 0;
}