#include <bits/stdc++.h>
using namespace std;
#define nodo pair<long long, long long>
#define f first 
#define s second

//https://vjudge.net/problem/UVA-10308

int v, e; 
const int MAX=10005; 
vector<nodo> ady[MAX]; 
long long dist[MAX]; 


nodo bfs(int s){
queue<int>q;
q.push(s);
long long max_s= -1;
dist[s]=0;
nodo m;
int actual, i, next;
while(q.size()>0){
	actual = q.front();
	q.pop();
	for(i =0; i<ady[actual].size(); i++){
		next = ady[actual][i].f;
	
	
		if(dist[next]==-1){
	
			dist[next]= dist[actual]+ady[actual][i].s;
			if(dist[next]>max_s){
				max_s= dist[next];
				m = make_pair(next, max_s);
			}
			q.push(next);
		}
	}
}
return m;
}

int main() {
	
   string a;
   memset(dist,-1, sizeof(dist));
   int ini;
   while(getline(cin,a)){
   	if(a==""){
   		//lanzar diametro
		nodo m = bfs(ini);
		memset(dist,-1, sizeof(dist));
		nodo n = bfs(m.f);
		cout<<n.s<<endl;
		//inicializar
		memset(dist,-1, sizeof(dist));
		for(int i =0; i<10005; i++){
			ady[i].clear();
		}
   	}else{
   		istringstream iss(a);
   		string s;
   		vector<long long>vals;
   		while(iss>>s){//lee 3
   			long long e = stoi(s);
   			vals.push_back(e);
   			}
   			ini = vals[0];
   		ady[vals[0]].push_back(make_pair(vals[1], vals[2]));	
   		ady[vals[1]].push_back(make_pair(vals[0], vals[2]));	
   	}
   }
	
	    nodo m = bfs(ini);
	  
		memset(dist,-1, sizeof(dist));
		nodo n = bfs(m.f);
		cout<<n.s<<endl;
	
	return 0;
}