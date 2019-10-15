#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int tam = 505; 
int dy[] = {1, 2,-2,-2, 2,-1, 1, -1}; 
int dx[] = {2,-1, 1,-1, 1, 2,-2, -2}; 
int grid[tam][tam]; 
int X, Y; 
int xini, yini, xfin, yfin;

//https://trainingcenter.cloud.ufps.edu.co/problemas/394/detalle/es



void floodfill() { 
	
	queue <pair<int, int> > q;
	q.push(make_pair(yini, xini));
	grid[yini][xini] = 0;
	while(q.size()){
		pair<int, int>a = q.front();
		q.pop();
	
		for (int i = 0; i < 8; i++){
			int y = a.f+dy[i] , x = a.s + dx[i];
			if (y < 0 || y >= Y || x < 0 || x >= X) continue;
			if(grid[y][x]!=-1)continue;
			
			grid[y][x]= grid[a.f][a.s]+1;
			
			if(y == yfin && x ==xfin)	return;
			
			q.push(make_pair(y,x));
			
		}

	}

}

 
int main() {
	while (cin>>Y){
		X=Y;
		cin>>yini>>xini>>yfin>>xfin;
		memset(grid, -1, sizeof(grid));
		
		floodfill();
		
		cout<<grid[yfin][xfin]<<endl;
	}
	return 0;
}
