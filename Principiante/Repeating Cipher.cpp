#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1095/problem/A

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	int n; string a; cin>>n>>a; int j = 1; 
	for(int i = 0; i<a.size(); i+= j, ++j)cout<<a[i];
	cout<<endl;
	
	return 0;
}