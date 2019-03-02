#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

//http://trainingcenter.ufps.edu.co/problemas/279/detalle/es

const int tam = 110; 
int dy[] = {1,0,-1, 0};
int dx[] = {0,1, 0,-1}; 
char grid[tam][tam]; 
int cant[tam][tam];
int X, Y; int ye,xe;

int floodfill(int y, int x) {
	if(grid[y][x] == '*' || grid[y][x] == 'w' )return -1;
	queue<pair<int,int>> q;
	pair<int,int> actual;
	q.push(mp(y,x));
	while(!q.empty()){
		actual = q.front(); q.pop();
		int y=actual.first; int x= actual.second;
		if(y==ye && x==xe) return cant[y][x];
		
		for(int i = 0; i<4; i++){
			int yy=y+dy[i]; int xx=x+dx[i];
			if (yy < 0 || yy >= Y || xx < 0 || xx >= X) continue;
			if(grid[yy][xx]=='*' || grid[yy][xx] == 'w' ) continue;
			q.push(mp(yy,xx));
			cant[yy][xx] = cant[y][x]+1;
			grid[yy][xx]='*';
		}
	}
	return -1;
}

int main() {
int casos; cin>>casos; string a; int ys, xs;
while(casos--){
	memset(cant,0,sizeof(cant));
	ye=xe=ys=xs=-1;
	cin>>Y>>X;
	vector<pair<pair<int, int>,char> > sensores;
	for(int i=0; i<Y; i++){
		cin>>a;
		for(int j=0; j<X; j++){
			grid[i][j] = a[j];
			if(grid[i][j] =='S')ys=i,xs=j;
			if(grid[i][j] =='E')ye=i,xe=j;
			if(a[j] == 'v' || a[j] == '^' || a[j] == '<' ||a[j] == '>') sensores.pb(mp(mp(i,j), a[j]));
		}
	}
	for(int i = 0; i<sensores.size(); i++){
		char v = sensores[i].second; int y = sensores[i].first.first; int x = sensores[i].first.second;
		int yy =y; int xx = x;
		if(v == '^'){
			yy--;
			while(yy>=0 && grid[yy][x]!= '*' && (grid[yy][x] != 'v' && grid[yy][x]!= '^' && grid[yy][x]!= '<' && grid[yy][x] != '>')){
				grid[yy][x] = 'w';

				yy--;
			
			}
		}
		
	else	if(v == 'v'){
		yy++;
			while(yy<Y && grid[yy][x]!= '*' &&((grid[yy][x] != 'v' && grid[yy][x]!= '^' && grid[yy][x]!= '<' &&grid[yy][x] != '>'))){
				grid[yy][x] = 'w';

				yy++;
			}
		}
		
	else 	if(v == '<'){
		xx--;
			while(xx>=0 && grid[y][xx]!= '*' && ((grid[y][xx] != 'v' && grid[y][xx]!= '^' && grid[y][xx]!= '<' &&grid[y][xx] != '>'))){
				grid[y][xx] = 'w';

				xx--;
		
			}
		}
		
	else	if(v == '>'){
		xx++;
			while(xx<X && grid[y][xx]!= '*' && ((grid[y][xx] != 'v' && grid[y][xx]!= '^' && grid[y][xx]!= '<' &&grid[y][xx] != '>'))){
					grid[y][xx] = 'w';

				xx++;
			}
		}
		
	}

	 if((ye==-1 && xe==-1) || (ys==-1 && xs==-1)){
	 	cout<<"Despertara gritando"<<endl;
	 }
	else{
int camino =	floodfill(ys,xs);
if(camino==-1)cout<<"Despertara gritando"<<endl;
else cout<<cant[ye][xe]<<endl;
}
}


	return 0;
}