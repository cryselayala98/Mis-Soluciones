#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-567

int v, e;
const int MAX=20; 
vector<int> ady[MAX]; 
long long dist[MAX][MAX]; 


void bfs(){
  queue<int> q;
  for(int k = 0; k<v; k++){
  int s = k;
  q.push(s); 
  dist[s][s] = 0;
  int actual, i, next;
  
  while( q.size() > 0 ){
    actual = q.front();
    q.pop();

    for( i = 0; i < ady[actual].size(); i++){
      next = ady[actual][i];
      if( dist[s][next] == -1 ){
        dist[s][next] = dist[s][actual] + 1;
        q.push(next);
      }
    }
  }
}

}

int main() {
	int t = 0;
	v=20; 
	int a,b;
	while(cin>>a){
		//if(t)cout<<endl;
		memset(dist, -1, sizeof(dist));
		for(int i =0; i<v; i++)ady[i].clear();
		
		while(a--){
			cin>>b;
			ady[0].push_back(b-1);
			ady[b-1].push_back(0);
		}
		
		for(int i = 1; i<v-1; i++){
			cin>>a;
			
			while(a--){
			cin>>b;
			ady[i].push_back(b-1);
			ady[b-1].push_back(i);
		}
		
		}
		t++;
		bfs();
		cout<<"Test Set #"<<t<<endl;
		
		int q; cin>>q;
		while(q--){
			cin>>a>>b;
			string aa = to_string(a); string bb = to_string(b);
			if(aa.size()<2)aa=" "+aa; 
			if(bb.size()<2)bb=" "+bb;
			cout<<aa<<" to "<<bb<<": "<<dist[a-1][b-1]<<endl;
		} cout<<endl;
	}
	
	return 0;
}