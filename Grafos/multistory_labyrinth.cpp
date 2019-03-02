#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=5027
const int tam =  205;
int dy[] = {1,0,-1, 0}; 
int dx[] = {0,1, 0,-1}; 
char grid[tam][tam][tam]; 
int X, Y, Z; 
long long dist[205][205][205];

void bfs(int y, int x, int z) { 
	queue<pair <int, pair<int, int> >> q;
	q.push(mp(z, mp(x,y)));
	dist[z][x][y] = 0;
	pair <int, pair<int, int> > actual, next;
	
	while(!q.empty()){
		actual = q.front();
		q.pop();
        if (actual.s.s < 0 || actual.s.s >= Y || actual.s.f < 0 || actual.s.f >= X || actual.f < 0 || actual.f >= Z) continue;
     
        for (int i = 0; i < 4; i++){
        	if( grid[actual.f][actual.s.f+dx[i]][actual.s.s+dy[i]] == '#' ) continue;
        	 next = mp(actual.f, mp(actual.s.f+dx[i], actual.s.s+dy[i]));
        	 if( dist[next.f][next.s.f][next.s.s] == -1 ){
        	 		dist[next.f][next.s.f][next.s.s] =dist[actual.f][actual.s.f][actual.s.s] +1;
        	 		q.push(next);
        	 }
        }
        if(grid[actual.f][actual.s.f][actual.s.s] == '-'){
        	next = mp(actual.f+1, mp(actual.s.f, actual.s.s));
            if(next.f<Z && grid[next.f][next.s.f][next.s.s] == '-' && dist[next.f][next.s.f][next.s.s] == -1 ){
        	 		dist[next.f][next.s.f][next.s.s] = dist[actual.f][actual.s.f][actual.s.s]  + 1;
        	 		q.push(next);
        	 }
            
	next = mp(actual.f-1, mp(actual.s.f, actual.s.s));
            if(next.f>=0 && grid[next.f][next.s.f][next.s.s] == '-' && dist[next.f][next.s.f][next.s.s] == -1 ){
        	 		dist[next.f][next.s.f][next.s.s] = dist[actual.f][actual.s.f][actual.s.s]  + 1;
        	 		q.push(next);
        	 }
        }
	if(grid[actual.f][actual.s.f][actual.s.s]== 'E') return;
	grid[actual.f][actual.s.f][actual.s.s] = '#';
	}       
}

int main() {
	int l,w,h; string a;
	while(cin>>w>>l>>h, h){
		Z = h ; X = w; Y = l;  
		memset(grid, '#', sizeof(grid));
		memset(dist, -1, sizeof(dist));
		pair <int, pair<int, int> >ini, fin;
		for(int i =0; i<h; i++){
			for(int j =0; j<w; j++){
				cin>>a;
				for(int k =0; k<l; k++) {
					grid[i][j][k] = a[k];	
					if(grid[i][j][k] == 'S') ini = mp(i, mp(j,k));
					else if(grid[i][j][k] == 'E') fin = mp(i, mp(j,k));
				}
		}
		   getline(cin, a);
		   getline(cin, a);
		}
		
		bfs(ini.s.s, ini.s.f, ini.f);
		int t = dist[fin.f][fin.s.f][fin.s.s];
		if(t==0) t = -1;
		cout<<t<<endl;
		
		
	}
	return 0;
}