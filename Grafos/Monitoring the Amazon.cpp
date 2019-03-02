#include <bits/stdc++.h>
using namespace std;
#define estacion pair<double, int>

//https://vjudge.net/problem/UVA-10687

struct point { 
	double x, y;
  	point() { x = y = 0.0; }
  	point(double _x, double _y) : x(_x), y(_y) {}        
  	bool operator == (point other) const {
   		return (fabs(x - other.x) < 1e-9 && (fabs(y - other.y) < 1e-9)); 
   	}
};

bool compare(point a, point b) {
	
	if(a.x<b.x) return 1;
	if(a.x == b.x && a.y<b.y) return 1;
	
	return 0;
	
}

double euclideanDistance(point p1, point p2) {           
  return hypot(p1.x - p2.x, p1.y - p2.y); 
} 

int v, e;
const int MAX=100005; 
vector<estacion> ady[MAX];
vector<point> estaciones;
bool marked[MAX]; 

static int dfs(int s){
	marked[s] = 1;
	int cont = 1;
	int i, next;

	for( i = 0; i < 2; i++ ){ //las 2 mas cercanas
		next = ady[s][i].second;
		if( !marked[next] ) cont+= dfs(next);
	}
	return cont;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	while(cin>>v, v){
		double y_ini, x_ini; int ini;
		memset(marked, 0, sizeof(marked));
		for(int i = 0; i<v; i++) ady[i].clear();
		estaciones.clear();
		
		double a,b;
		
		for(int i = 0; i<v; i++){
			cin>>a>>b;
			estaciones.push_back(point(a,b));
			if(!i) x_ini = a, y_ini = b;
		}
		
		sort(estaciones.begin(), estaciones.end(), compare); //ordenar 1 y 2 criterio en caso de empate
		
		for(int i = 0; i < v; i++){
			if(x_ini == estaciones[i].x && y_ini == estaciones[i].y){
				ini = i; break;
			}
		}
		
		//definir distancias
		for(int i = 0; i<v-1; i++){
			for(int j = i+1; j<v; j++){
					double d = euclideanDistance(estaciones[i], estaciones[j]);
					ady[i].push_back(make_pair(d,j));
					ady[j].push_back(make_pair(d,i));
			}
			sort(ady[i].begin(), ady[i].end());
		
		} 	sort(ady[v-1].begin(), ady[v-1].end());
		
		int cont = dfs(ini);
		if(cont<v) cout<<"There are stations that are unreachable.\n";
		else cout<<"All stations are reachable.\n";
	}
	
	
	return 0;
}