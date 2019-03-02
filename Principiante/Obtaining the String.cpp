#include <bits/stdc++.h>
using namespace std;

map<char, int> v ;
//https://codeforces.com/contest/1015/problem/B

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	string s,t; int n;
	cin>>n>>s>>t;
	
	for(int i =0; i<s.size(); i++) v[s[i]]++;
	for(int i =0; i<t.size(); i++) v[t[i]]--;
	
	bool es= 0;
	for(auto x : v){
		if(x.second != 0){
			cout<<-1<<endl;
			es = 1; break;
		}
	}
	
	vector <int> sw;
	if(!es){
	for(int i = 0; i<s.size(); i++){
		if(s[i]!=t[i]){
			int j;
			for(j = i+1; j<s.size(); j++){
				if(s[j]== t[i])break;
			}
			for(int k = j-1; k>=i; k--){
				swap(s[k+1], s[k]);
				sw.push_back(k);
			}
		}
	}
	
	cout<<sw.size()<<endl;
	for(int i =0; i<sw.size(); i++){
		if(i) cout<<" ";
		cout<<sw[i]+1;
	}
		cout<<endl;
	}

	
	return 0;
}