#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/236607/problem/D

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	long long r,g,b;cin>>r>>g>>b;
	cout<<min((r+g+b)/3, min(r+g, min(g+b, r+b)));
	
	return 0;
}