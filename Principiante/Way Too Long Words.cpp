#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/71/A

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int c; string a; 
	cin>>c;
	while(c--){
		cin>>a;
		if(a.size()<=10)cout<<a<<endl;
		else cout<<a[0]<<a.size()-2<<a[a.size()-1]<<endl;
	}
	return 0;
}