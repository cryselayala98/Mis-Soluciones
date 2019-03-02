#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/237999/problem/C

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t ; cin>>t;
	while(t--){
		int a,b; string c;
		cin>>a>>c>>b;
		int r = 2*b;
		if(c=="even") r--;
		cout<<r<<endl;
	}
	return 0;
}