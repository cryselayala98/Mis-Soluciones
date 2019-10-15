#include <bits/stdc++.h>
using namespace std;
#define cajera pair<int, pair<int, int> > //t_total, menor tiempo caminando, indice
#define f first
#define s second

//https://trainingcenter.cloud.ufps.edu.co/problemas/335/detalle/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n;
	while(cin>>n){
		
		vector<int> ti, pi;
		
		int a, act;
		
		for(int i = 0; i<n; i++){
			cin>>a;
			ti.push_back(a);
		}
		for(int i = 0; i<n; i++){
			cin>>a;
			ti[i] = ti[i]*a;
		}
		for(int i = 0; i<n; i++){
			cin>>a;
			if(!i)	pi.push_back(0);
			else pi.push_back(a+pi[i-1]);
		}
		cin>>act; act--;
		set<cajera> ca;
		for(int i = 0; i<n; i++){
			int total = ti[i] + abs(pi[i]-pi[act]);
			ca.insert(make_pair(total, make_pair(abs(pi[i]-pi[act]), i+1)));
		}
		auto x = *ca.begin();
		cout<<x.s.s<<" "<<x.f<<endl;
	}
	return 0;
}
