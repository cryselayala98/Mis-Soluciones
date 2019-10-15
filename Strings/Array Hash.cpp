#include <bits/stdc++.h>
using namespace std;

//https://www.urionlinejudge.com.br/judge/es/problems/view/1257

int main() {
	int t; cin>>t;
	while(t--){
		int n,total = 0;
		cin>>n; string a;
		for(int i = 0;i<n; i++){
			cin>>a;
			for(int j = 0; j<a.size(); j++)total+=(a[j]-'A')+ i + j;
		}
		cout<<total<<endl;
	}
	return 0;
}