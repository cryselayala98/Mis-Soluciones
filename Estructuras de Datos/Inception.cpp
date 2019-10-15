#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-13055

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int q; cin>>q;
	stack<string> act;
	string a; stack <string>g;
	while(q--){
		cin>>a;
		if(a=="Sleep") {
			cin>>a;
			g.push(a);	
		}else if(a=="Kick"){if(g.size())g.pop();}
		else {
			if(g.size())cout<<g.top()<<endl;
			else cout<<"Not in a dream"<<endl;
		}
	}
	return 0;
}
