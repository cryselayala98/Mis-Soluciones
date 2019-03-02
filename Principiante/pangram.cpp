#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/520/A

int main() {
	int n; string a;
	
	while(cin>>n>>a){
		set<char> pangram;
		for(int i =0; i<n; i++) pangram.insert(tolower(a[i]));
		if(pangram.size()==26)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}