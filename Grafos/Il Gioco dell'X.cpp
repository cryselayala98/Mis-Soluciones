#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-260

const int tam = 205; 
int dy[] = {1,1,0,-1,-1, 0}; 
int dx[] = {0,1,1, 0,-1,-1}; 
char grid[tam][tam]; 
int X, Y; 
int winner; //1:black, 0:white

void floodfill(int y, int x, char c1, char c2) { 
	if (y < 0 || y >= Y || x < 0 || x >= X) return;
	if (grid[y][x] != c1) return; 
	grid[y][x] = c2; 
	if(y==Y-1){
		winner = 1;
		return;
	} 
	
	for (int i = 0; i < 6 && !winner; i++)
		floodfill(y + dy[i], x + dx[i], c1, c2);
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t = 1;
	while(cin>>Y, Y){
		X = Y;
		cout<<t<<" "; t++;
		string a;
		for(int i = 0; i<Y; i++){
			cin>>a;
			for(int j= 0; j<Y; j++){
				grid[i][j] = a[j];
			}
		}
		winner = 0;
		for(int x = 0; x<X; x++){
			if(grid[0][x]=='b'){
				floodfill(0,x,'b','x');
				if(winner) goto final;
			}
		}
		final:
		if(winner)cout<<"B"<<endl;
		else cout<<"W"<<endl;
	}
	
	return 0;
}