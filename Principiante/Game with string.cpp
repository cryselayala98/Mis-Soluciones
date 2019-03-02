#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1104/problem/B

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	string a; cin>>a;
	
	a = "12345"+a+"12345";
	
	int cont =0;
	for(int i = 5; i<a.size()-5; i++){
		if(a[i]==a[i+1]){
			cont++;
			a.erase(a.begin()+i+1);
			a.erase(a.begin()+i);
			i-=2;
		}
	}
	if(cont%2==0)cout<<"No\n";
	else cout<<"Yes\n";
	return 0;
}