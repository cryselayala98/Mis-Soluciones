#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair

//https://codeforces.com/contest/557/problem/D


long long v, e;
const int MAX=100005;
vector<int> ady[MAX];
int color[MAX];
bool bipartite;
vector<pair<bool, pair<int, int> > >parejas;


pair<bool, pair<int, int> > bfs(int s){
  pair<bool, pair<int, int> >  aux= mp(1, mp(0,0));
  queue<int> q;
  q.push(s);
  color[s] = 0;
  aux.s.f++;
  int actual, i, next;

  while( q.size() > 0 ){
    actual = q.front();
    q.pop();

    for( i = 0; i < ady[actual].size(); i++){
      next = ady[actual][i];
      if( color[next] == -1 ){
        color[next] = 1 - color[actual];

        if(color[next]== 1 )aux.s.s++;
		else aux.s.f++;
        q.push(next);
      }else if( color[next] == color[actual] ){
        aux.f = 0;
        return aux;
      }
    }
  }
	return aux;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

   /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
   
	
	cin>>v>>e;
	long long a,b;
	memset(color, -1, sizeof(color));
	int aristas=0;
	while(e--){
		aristas++;
		cin>>a>>b;
		ady[a-1].pb(b-1);
		ady[b-1].pb(a-1);
	}
	
	if(!aristas){
		long long res = ((v * (v - 1) * (v - 2)) / 6 );
		cout<<"3 "<<res<<"\n";
	}else{
		int max_vertices = 0; //en cada componente
		int no_b = 0;
		for(int i = 0; i<v; i++){
			if(color[i]== -1){
				pair<bool,pair<int, int> > aux = bfs(i);
				max_vertices = max(max_vertices, aux.s.f + aux.s.s);
				if(!aux.f)no_b++;
				parejas.pb(aux);
			}
		}
		
		if(max_vertices<=2){
			cout<<" 2 "<<aristas * (v - 2)<<"\n";
		}else{
			
			if(no_b){ //componentes no bipartitos
				cout<<"0 1\n";
			}else{
				long long res = 0;
				for(int i =0; i<parejas.size();i++){
					a = parejas[i].s.f; b = parejas[i].s.s;
					if(a+b>2)res+= ((a * (a - 1)) / 2) + ((b * (b - 1)) / 2);
				}
				cout<<"1 "<<res<<"\n";
			}
		}
	}
	
    return 0;
}



