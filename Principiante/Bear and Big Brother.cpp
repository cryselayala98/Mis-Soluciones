#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/791/A

int main() {
	int l,b; cin>>l>>b;
	int cont =0;
	
	while(l<=b) l*=3, b*=2, cont++;
	
	cout<<cont<<endl;
	return 0;
}