#include <bits/stdc++.h>
using namespace std;
#define equipo pair<int, pair<int, pair<int, string> > > //mayor cant ejercicios, menor penalidad, mayor first sol, menor nombre eq
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i = 0; i<n; i++)

//https://trainingcenter.cloud.ufps.edu.co/problemas/365/detalle/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int t ; cin>>t;
	int ca=1;
	while(t--){
		cout<<"Competencia "<<ca<<":\n";
		ca++;
		int n, k;
		cin>>n;
		vector<equipo> eqs; set<equipo> rank; map<string, int> participantes;
		bitset <12> first_sol;
		
		set<string> veredictos;
		
		veredictos.insert("ACC");
		veredictos.insert("WA");
		veredictos.insert("CE");
		veredictos.insert("TLE");
		veredictos.insert("RTE");
		veredictos.insert("MLE");
		
		string a; getline(cin, a);
		
		forn(i,n){
			getline(cin, a);
			participantes[a+" "]=i;
			eqs.pb(mp(0, mp(0, mp(0, a+" "))));
		}
		
		cin>>k; getline(cin, a);
		forn(i,k){
			getline(cin, a);
			int tiempo;
			
			istringstream iss(a);
			string subs; int j = 0; string b="",veredicto="*"; char ejercicio; 
			while (iss >> subs) {
				if(j==0) tiempo = stoi(subs);
				else if(veredicto!="*") ejercicio = subs[0];
				else{
					if(!veredictos.count(subs))b+=subs+" ";
					else veredicto = subs;
				}
				j++;
			}
			//cout<<b<<" "<<tiempo<<" "<<veredicto<<" "<<ejercicio<<endl;
			
			//cant ejercicios
			int idx= participantes[b];
			if(veredicto=="ACC"){
				eqs[idx].f ++;
				eqs[idx].s.f+=tiempo; //penalidad
				
				int idx_ej = ejercicio - 'A';
				if(!first_sol[idx_ej])eqs[idx].s.s.f++; //first sol en un ej
				first_sol[idx_ej] = 1;
			}else{
				eqs[idx].s.f+=20; ////penalidad no acc
			}
		}
		
		forn(i,n){
			rank.insert(mp((eqs[i].f)*-1, mp(eqs[i].s.f, mp((eqs[i].s.s.f)*-1, eqs[i].s.s.s))));
		}
		
		int eq = 1;
		for(auto x : rank){
			cout<<eq<<". "<<x.s.s.s<<(x.f)*-1<<" "<<x.s.f<<" "<<(x.s.s.f)*-1<<endl;
			eq++; 
		}
		if(t)cout<<endl;
	}
	return 0;
}
