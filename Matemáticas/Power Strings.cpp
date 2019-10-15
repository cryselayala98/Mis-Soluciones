#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-10298

bool verificar_rep(string p, string s){
	int v=1;
	for(int i =0; i<s.size()/p.size(); i++){
		string f= s.substr(p.size()*i, p.size());
		if(f!=p) return 0;
	}
	return v;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	string s; 
	
	while(cin>>s && s!="."){
		vector<int>vals ; 
		for(int n=1; n<=sqrt(s.size()); n++){
			if(s.size()%n==0){
				vals.push_back(n);
				vals.push_back(s.size()/n);
			}
		}
		
		sort(vals.rbegin(),vals.rend());
		int n = 1;
		
		for(auto x: vals){
			bool v = verificar_rep(s.substr(0, x), s);
			if(v){n=s.size()/x; }
		}
		
		cout<<n<<endl;	
	}
	return 0;
}
