#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVALive-5334

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int y,x, i,j; 
	
	while(cin>>y>>x>>j, y+x+j){
	i = 0; j--;
	char grid[y][x];
	string a;
	for(int k = 0; k<y; k++){
		cin>>a;
		for(int k2 = 0; k2<x; k2++) grid[k][k2] = a[k2];
	}
	int pasos=0;
	while(1){
		int yy=0,xx=0;
		char actual = grid[i][j];
		if(actual == 'N') yy--;
		else if(actual == 'S') yy++;
		else if(actual == 'E') xx++;
		else if(actual == 'W') xx--;
		else{  //find a cycle
			cout<<(int)actual - 1<<" step(s) before a loop of "<<pasos - (int)actual+1<<" step(s)"<<endl;
			break;
		}
		pasos++;
		grid[i][j] = pasos;
		i+=yy; j+= xx;
		if(i<0 || j<0 || i>=y ||j>=x){
			cout<<pasos<<" step(s) to exit"<<endl;
			break;
		}
	}
	
	}
	
	return 0;
}