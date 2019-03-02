#include <bits/stdc++.h>
using namespace std;
#define nodo pair<int, int>
#define f first
#define s second

//https://codeforces.com/problemset/problem/61/D

int v, e; 
const int MAX=100005; 
vector<nodo> ady[MAX]; 
long long dist[MAX]; 


long long bfs(int s){
  long long maxi =0; 
  queue<nodo> q;
  q.push(make_pair(s,0)); 
  dist[s] = 0;
  nodo actual, next; int i;
       
  while( q.size() > 0 ){
    actual = q.front();
    q.pop();

    for( i = 0; i < ady[actual.f].size(); i++){
      next = ady[actual.f][i];
      if( dist[next.f] == -1 ){
        dist[next.f] = dist[actual.f] + next.s;
        
        maxi= max(maxi, dist[next.f]);
        q.push(next);
      }
    }
  }
	return maxi;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	memset(dist, -1, sizeof(dist));
	cin>>v; int a,b,c;
	v--;
	long long cont =0;
	while(v--){
		cin>>a>>b>>c;
		cont+=c;
		ady[a-1].push_back(make_pair(b-1,c));
		ady[b-1].push_back(make_pair(a-1,c));
	}
	cont*=2;
	long long maxi = bfs(0);
	
	cout<<cont-maxi<<endl;
	return 0;
}