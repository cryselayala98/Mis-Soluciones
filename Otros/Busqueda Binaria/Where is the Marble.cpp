#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-10474

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n,q; 
	int cases = 1;
	while(cin>>n>>q, n+q){
		cout<<"CASE# "<<cases<<":"<<endl;
		cases++;
		vector<int>vals; int a;
		for(int i = 0; i<n; i++){
			cin>>a;
			vals.push_back(a);
		}
		sort(vals.begin(), vals.end());
		
		while(q--){
			cin>>a;
			int pos = find(vals.begin(), vals.end(), a) - vals.begin();
			if(pos==n)cout<<a<<" not found"<<endl;
			else cout<<a<<" found at "<<pos+1<<endl;
		}
	}
	return 0;
}
