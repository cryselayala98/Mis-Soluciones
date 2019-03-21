#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second

//https://codeforces.com/contest/877/problem/D


const int tam = 1005; 
int dy[] = {1,0,-1, 0}; 
int dx[] = {0,1, 0,-1}; 
char grid[tam][tam]; 
int camino[tam][tam];
int X, Y; 


void floodfill(int y, int x, int y1, int x1, int k) { 
	camino[y][x] = 0;
	queue <pair<int, int> > q;
	q.push(mp(y,x));
	grid[y][x] = 'i';
	
	pair<int, int> actual, next;
	
	while(!q.empty()){
		actual = q.front();
	    q.pop();
	    
    if(actual.f==y1 && actual.s==x1) return;
	    for(int i =0; i<4; i++){
	    	for(int j =1; j<=k; j++){
	    		int yy = actual.f + dy[i]*j; int xx = actual.s + dx[i]*j;
	    		if (yy < 0 || yy >= Y || xx < 0 || xx >= X) break;
	    	    if (grid[yy][xx] != '.' || camino[yy][xx]<= camino[actual.f][actual.s]) break;
	    	    
	    	    if(grid[yy][xx] == '.' && camino[yy][xx] > camino[actual.f][actual.s] + 1){
	    	    	camino[yy][xx] = camino[actual.f][actual.second] + 1;
	    	    	next = mp(yy, xx);
	    			q.push(next);
	    		
	    	    }
	    	}
	    }
	    	
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int k,y,x,x1,y1;
	for(int i =0; i<tam; i++) for(int j =0; j<tam; j++) camino[i][j]=1e8;
	cin>>Y>>X>>k;
	
	for(int i = 0; i<Y; i++){
		for(int j = 0; j<X; j++){
			cin>>grid[i][j];
		}
	}
	
	cin>>y>>x>>y1>>x1;
	--y; --x; --y1; --x1;
	floodfill(y,x,y1,x1,k);
	
	cout<<(camino[y1][x1]==1e8 ? -1:camino[y1][x1])<<endl;
	
	return 0;
}
