#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/705/A
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int capas; cin>>capas;
	bool s = 0;
	while(capas--){
		if(!s)cout<<"I hate";
		else cout<<"I love";
		s=not(s);
		if(capas>0)cout<<" that ";
	}
	cout<<" it\n";
	return 0;
}