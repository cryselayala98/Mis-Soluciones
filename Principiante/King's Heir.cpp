#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101142 ejercicio k

long long dias_mes [] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);

	string a,b,c; cin>>a>>b>>c;
	
	int d_meses = 0; int y =stoi(b);
	for(int i = 0; i<y; i++) d_meses += dias_mes[i];
	long long dias = stoi(a) + d_meses + (stoi(c)*365);
	int n; cin>>n; vector<pair<int, int> > hijos_candidatos;
	
	for(int i = 1; i<=n; i++){
		cin>>a>>b>>c;
		
		d_meses = 0; int y =stoi(b);
		for(int i = 0; i<y; i++) d_meses += dias_mes[i];
		int dias_h = stoi(a) + d_meses + (stoi(c)*365);
		hijos_candidatos.push_back(make_pair(dias_h, i));
	}
	
	sort(hijos_candidatos.rbegin(), hijos_candidatos.rend());
	
	int f = -1;
	for(int i = 0; i<n; i++){
		if(dias - hijos_candidatos[i].first >=6570){
			f = hijos_candidatos[i].second;
			break;
		} 
	}
	cout<<f<<endl;
	
	return 0;
}