#include <bits/stdc++.h>
using namespace std;

https://codeforces.com/gym/101972/problem/D

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int c,n,x,y;
	cin>>c;
	while(c--){
		cin>>n>>x>>y;
		if((n/2)+1 <= x && n/2 <=y)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}