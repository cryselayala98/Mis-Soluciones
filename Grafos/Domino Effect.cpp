#include <bits/stdc++.h>
using namespace std;
#define nodo pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair

//https://vjudge.net/problem/UVA-318

double ady[500][500];
bool d[500][500];
bool marked[500];
vector<nodo> v,del;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int s=0;
	int n,m;
	while(cin>>n>>m, n){
		s++;
		v.clear(); del.clear();
		for(int i=0; i<n; i++) marked[i]=0;
		int a,b; double c;
		
		while(m--){
			cin>>a>>b>>c;
			d[a-1][b-1]= 0;
			d[b-1][a-1]= 0; 
			ady[a-1][b-1]= c;
			ady[b-1][a-1]= c;
		}
		
		marked[0] =1;
		for(int i =0; i<n; i++){
		if(ady[0][i]>0){
				v.pb(mp(0,i));
			}	
		} 
		double res=0;
		
		while(!v.empty()){
			del.clear();
			double men = 1000000.0;
			sort(v.begin(), v.end());
			for(int i =0; i<v.size(); i++) men = min(men, ady[v[i].f][v[i].s]);
			
			res+= men;
			int t = v.size();
			for(int i =0; i< t; i++){
				
				ady[v[i].f][v[i].s] -= men;
				ady[v[i].s][v[i].f] -= men;
				if(ady[v[i].f][v[i].s] == 0){
					del.pb(v[i]);
					
					v.erase(v.begin()+i);
					i--; t--;
					}
			}
			
			for(int i =0; i< del.size(); i++){
				
					if(marked[del[i].s]==0){
			
					marked[del[i].s]=1;
					
					for(int j =0; j<n; j++){
						
						
						if(ady[del[i].s][j]>0){
							if(marked[j]){
								
								d[del[i].s][j]=1;
								d[j][del[i].s]=1;
								
								ady[del[i].s][j] = ady[del[i].s][j]/2;
								ady[j][del[i].s] = ady[j][del[i].s]/2;
						
							}else{
							
								v.pb(mp(del[i].s, j));
							}
						}
					}
				}
					
				
				
			}
		}
		cout<<"System #"<<s<<"\n";
		if(n==1){
			cout<<"The last domino falls after 0.0 seconds, at key domino 1.\n";
		}else{
			cout<<"The last domino falls after "<<fixed << setprecision(1) << res<<" seconds, ";
			if(d[del[del.size()-1].f][del[del.size()-1].s]) cout<<"between key dominoes "<<min(del[del.size()-1].f+1, del[del.size()-1].s+1)<<" and "<<max(del[del.size()-1].f+1, del[del.size()-1].s+1)<<".\n";
			else cout<<"at key domino "<<del[del.size()-1].s+1<<".\n";	
		}
		cout<<"\n";
	}
	return 0;
}