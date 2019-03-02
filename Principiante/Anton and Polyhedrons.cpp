#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/785/A

int wii [150];

int main() {
	
	ios::sync_with_stdio(0); cin.tie(NULL);
	wii['T'] = 4; 	wii['C'] = 6; 	wii['O'] = 8; 	wii['D'] = 12; 	wii['I'] = 20;
	
	string a; int b; cin>>b;
	
	int res=0;
	while(b--){
		cin>>a;
		res+= wii[a[0]];
	} cout<<res<<endl;
	
	return 0;
}