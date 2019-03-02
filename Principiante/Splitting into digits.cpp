#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1104/problem/A

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; cin>>n;
	int divi = 0; 
	for(int i = 9; i>= 1; i--){
		if(n%i == 0){
			divi = i;
			break;
		}
	}
	if(divi == 0){
		cout<<1<<endl<<n;
	}else{
		cout<<n/divi<<endl;
		for(int i = 0; i< n/divi; i++){
			if(i)cout<<" ";
			cout<<divi;
		} cout<<endl;
	}
	return 0;
}