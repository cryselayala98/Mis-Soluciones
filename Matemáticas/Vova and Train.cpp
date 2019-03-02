#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1066/problem/A

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int L,v,l,r,q;
	cin>>q;
	
	while(q--){
		cin>>L>>v>>l>>r;
		
		int t = L / v;
		
		l = (l%v == 0)?l:l + (v - (l%v));
		r = r - (r%v);
		if(r>=l)t -= (r/v - l/v) + 1;
		
		cout<<t<<endl;
	}
	return 0;
}