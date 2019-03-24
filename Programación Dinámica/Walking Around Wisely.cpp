#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-926

int dx[] = {-1,0}; 
int dy[] = { 0,1};

int dxx[] = {-1,1,0,0}; 
int dyy[] = { 0,0,1,-1};

long long grid[31][31]; bool discontinued [31][31][31][31];
int n, xs, ys, xf, yf, blocked, a,b; char dir;
long long  w ;

long long ways(int x, int y, int xx, int yy){ //d es la direccion de donde viene :3

	if(xx<0 || xx>=n || yy<0 || yy>=n ) return 0;
	if(discontinued[x][y][xx][yy]) return 0;
	
	
	if(xx== xf && yy == yf){
		return 1;
	}
	
	if(grid[xx][yy]>-1) return grid[xx][yy];
	
	
	
	long long p = 0;
	
	for(int i = 0; i<2; i++){
		p+= ways(xx,yy,xx+dx[i], yy+dy[i]);
	}
	grid[xx][yy] = p;
	
	 
	return p;
}



int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int cases; cin>>cases;
	
	while(cases--){
		cin>>n>>xs>>ys>>xf>>yf;
		xs--; ys--; xf--; yf--;
		swap(xs, ys); swap(xf,yf);
		xs = n-xs-1; xf = n-xf-1;
		cin>>blocked;
		memset(discontinued, 0, sizeof(discontinued));
		memset(grid, -1, sizeof(grid));
		
		
		while(blocked--){
			cin>>a>>b>>dir;
			a--; b--; swap(a,b);
			a = n-a-1;
			int v ;
		
			if(dir == 'N') v=0;
			else if(dir == 'S') v=1;
			else if(dir=='E')v = 2;
			else  v = 3; //dir -> W
			
			discontinued [a][b][a+dxx[v]][b+dyy[v]] = 1;
			discontinued [a+dxx[v]][b+dyy[v]][a][b] = 1;
		}
		w = ways(xs, ys, xs, ys);
		
		cout<<w<<endl;
	}
	return 0;
}