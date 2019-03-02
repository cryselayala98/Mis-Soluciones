#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/231/A

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n,a,b,c;
	cin>>n;
	int res=0;
	while(n--){
		cin>>a>>b>>c;
		if(a+b+c >=2) res++;
	}
	
	cout<<res<<endl;
	return 0;
}