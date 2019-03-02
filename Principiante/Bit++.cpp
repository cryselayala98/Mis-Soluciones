#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/282/A


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n; string a;
	cin>>n;
	int res=0;
	while(n--){
		cin>>a;
		if(a=="X++" || a=="++X") res++;
		else res--;
	}
	
	cout<<res<<endl;
	return 0;
}