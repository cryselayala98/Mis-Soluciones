#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-259
//tutorial : https://saicheems.wordpress.com/2013/09/22/uva-259-software-allocation/

const int MAX = 50;
vector<int> ady [MAX]; 
vector<int>orden;
int capacity [MAX] [MAX]; 
int flow [MAX] [MAX]; 
int previous [MAX];

void connect(int i, int j, int cap){
    ady[i].push_back(j);
    ady[j].push_back(i);
    capacity[i][j] += cap;
  
}

int maxflow(int s, int t, int n){ 
    int i, j, maxFlow, u, v, extra, start, end;
    for( i = 0; i <= n; i++ ){
        for( j = 0; j <= n; j++ ){
            flow[i][j]=0;
        }
    }

    maxFlow = 0;

    while( true ){
    	//bfs
        for( i = 0; i <= n; i++ ) previous[i] = -1;

        queue<int> q;
        q.push(s);
        previous[s] = -2;

        while( q.size() > 0 ){
            u = q.front();
            q.pop();
            if( u == t ) break;
            for( j = 0; j < ady[u].size(); j++){
                v = ady[u][j];
                if( previous[v] == -1  && capacity[u][v] - flow[u][v] > 0 ){
                    q.push(v);
                    previous[v] = u;
                }
            }
        }
        if( previous[t] == -1 ) break;

        extra = 1 << 30;
        end = t;
        while( end != s){
            start = previous[end];
            extra = min( extra, capacity[start][end]-flow[start][end] );
            end = start;
        }

        end = t;
        while( end != s){
            start = previous[end];
            flow[start][end] += extra;
            flow[end][start] = -flow[start][end];
            end = start;
        }

        maxFlow += extra;
    }

    return maxFlow;
}

void init(){
	for(int i = 0; i<MAX; i++){
		ady[i].clear();
		for(int j = 0; j<MAX; j++) capacity[i][j] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	string str;
	init();
	int a = 0; bool es= 0;
	while(getline(cin, str)){
		es = 1;
		if(str.size()){
			istringstream iss(str);
			string subs; int i = 0; int compu;
			int app; int cnt;
			
			//nodo 48=fuente, nodo 49=final
			
			while (iss >> subs) {
				if(!i){
					app = subs[0] - 'A'; cnt = subs[1] - '0';
					a+= cnt;
					orden.push_back(app);
					connect( 48, orden.size()-1, cnt); 
				}else{
					for(int j = 0; j< subs.size()-1; j++){
						compu = '[' - subs[j];
						connect(orden.size()-1, compu, 1000000000); 
					}
				}
				
				i++;
			}
			
		}else{
		
			for(int i = 34 ; i<=43;i++){ //nodos de las computadoras
				connect(i,49, 1);	
			}
			
			int conf = maxflow(48,49,49);
			if(conf < a)cout<<"!\n";
			else{
				string u = "__________";
				for(int i = 0; i<orden.size(); i++){
					for(int j = 0; j<10; j++){
							if(flow[i][j+34]) u[j] = (char)orden[i]+'A';
					}
				}
				reverse(u.begin(), u.end());
				cout<<u<<endl;
			}
			init();
			a = 0;
			orden.clear();
		}
	}
	
	//para el ultimo caso
	if(es){ //si al menos existe un caso de prueba
	for(int i = 34 ; i<=43;i++){ //nodos de las computadoras
				connect(i,49, 1);	
			}
			
			int conf = maxflow(48,49,49);
		//	cout<<conf<<endl;
			if(conf < a)cout<<"!\n";
			else{
				string u = "__________";
				for(int i = 0; i<orden.size(); i++){
					for(int j = 0; j<10; j++){
							if(flow[i][j+34]) u[j] = (char)orden[i]+'A';
					}
				}
				reverse(u.begin(), u.end());
				cout<<u<<endl;
			}
		
	}
    
	return 0;
}
