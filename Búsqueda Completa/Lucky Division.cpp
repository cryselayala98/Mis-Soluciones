#include <bits/stdc++.h>
using namespace std;

int lucky[]= {4,7,44,47,74,77,444,447,474,477,744,747,774,777};

//https://codeforces.com/problemset/problem/122/A

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; cin>>n;
	bool es =0;
	
	for(int i = 0; i<14; i++){
		if(n % lucky[i] == 0){
			es  = 1; break;
		}
	}
	
	if(!es)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}