#include <bits/stdc++.h>
using namespace std;

//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

int v, e; 
const int MAX=1005; 
vector<int> ady[MAX];
int dist[MAX]; 
bool girls[MAX];

void bfs(int s){
  queue<int> q;
  q.push(s); 
  dist[s] = 0;
  int actual, i, next;
       
  while( q.size() > 0 ){
    actual = q.front();
    q.pop();

    for( i = 0; i < ady[actual].size(); i++){
      next = ady[actual][i];
      if( dist[next] == -1 ){
        dist[next] = dist[actual] + 1;
        q.push(next);
      }
    }
  }

}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	memset(dist, -1, sizeof(dist));
	memset(girls, 0, sizeof(girls));
	
	int a,b;
	cin>>v;e = v-1;
	while(e--){
		cin>>a>>b;
		ady[a-1].push_back(b-1);
		ady[b-1].push_back(a-1);
	}
	cin>>a;
	while(a--){
		cin>>b; 
		girls[b-1] = 1;
	}
	
	bfs(0);
	
	int men = 10000; int girlfriend;
	
	for(int i = 0; i<v; i++){
		if(dist[i]<men && girls[i]) men = dist[i], girlfriend = i+1;
	}
	
	cout<<girlfriend<<endl;
	
	return 0;
}