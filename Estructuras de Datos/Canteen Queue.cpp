#include <bits/stdc++.h>
using namespace std;

//https://www.urionlinejudge.com.br/judge/es/problems/view/1548

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int t; cin>>t;
	while(t--){
		int a,b;
		cin>>a;
		queue<int> s;
		priority_queue<int> q;
		while(a--){
			cin>>b;
			s.push(b);
			q.push(b);
		}
		
		int acum=0;
		while(!s.empty()){
			a=q.top(); b = s.front();
			q.pop(); s.pop();
			
			acum+=(a==b)?1:0;
		}
		cout<<acum<<endl;
	}
	return 0;
}