#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-614

int dy[] = {0,-1,0,1}; 
int dx[] = {-1,0,1,0}; 
int grid[13][13]; 
bool mark[30][30];
int X, Y; 


bool floodfill(int y, int x, int yf, int xf, int cont) { 

	grid[y][x] = ++cont;
	if(y == yf && x == xf){
		return 1;
	} 
	
	
	for (int i = 0; i < 4; i++){
		if (y + dy[i] < 0 || y + dy[i] >= Y || x + dx[i] < 0 || x + dx[i] >= X) continue;
		if(mark[y*2 + dy[i]][x*2 + dx[i]]) continue; //pared
		if(grid[y + dy[i]][x + dx[i]]!=0) continue;
		bool ans = floodfill(y + dy[i], x + dx[i], yf, xf, cont);	
		if(ans) return 1;
	}
		
	
	grid[y][x]=-1; return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int i,j, i_f,j_f, a; int maze = 1;
	
	while(cin>>Y>>X>>i>>j>>i_f>>j_f, Y){
		memset(mark, 0, sizeof(mark));
		memset(grid, 0, sizeof(grid));
		
		for(int ii = 0;ii<Y; ii++){
			for(int jj = 0;jj<X; jj++){
				cin>>a;
				//paredes
				if(a==1)mark[ii*2][(jj*2)+1] = 1;
				else if(a==2) mark[(ii*2)+1][jj*2] = 1;
				else if(a==3) mark[(ii*2)+1][jj*2] = 1, mark[ii*2][(jj*2)+1] = 1;
		}
		}
		floodfill(i-1, j-1, i_f-1, j_f-1, 0);
		
		cout<<"Maze "<<maze<<endl<<endl<<"+";
		for(i = 0; i< X; i++)cout<<"---+";
		cout<<endl<<"|";
		
		for(int ii = 0;ii<Y; ii++){
			
			for(int jj = 0;jj<X; jj++){
				if(grid[ii][jj]==-1)cout<<"???";
				else if(grid[ii][jj]>9) cout<<" "<<grid[ii][jj];
				else if(grid[ii][jj]>0) cout<<"  "<<grid[ii][jj];
				else cout<<"   ";
				if(jj<X-1){
					if(mark[ii*2][(jj*2)+1]) cout<<"|";
					else cout<<" ";	
				}
			}
			cout<<"|\n+";
			for(i = 0; i< X; i++){
				if(ii==Y-1){
					cout<<"---+";
				}else{
				if(mark[(ii*2)+1][i*2])cout<<"---+";
				else cout<<"   +";
				}
			}
			if(ii<Y-1)cout<<"\n|";
		}cout<<endl<<endl<<endl;
		
		maze++;
	}
	return 0;
}