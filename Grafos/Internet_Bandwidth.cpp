#include<bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=761

vector<int> ady [105]; 
int capacity [105] [105]; 
int flow [105] [105]; 
int previous [105];

void init(int n){
	for( int j = 0; j <= n; j++ ) {
        ady[j].clear(); 
        memset(capacity, 0, sizeof(capacity));	
    }
}

void connect(int i, int j, int cap){
    ady[i].push_back(j);
    ady[j].push_back(i);
    capacity[i][j] += cap;
    capacity[j][i]+=cap;
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


int main() {
	int casos = 0;
	int s,t,n,a,b,c,d;
	while(cin>>n, n){
		casos++;
		init(n);
		cin>>s>>t>>a;
		while(a--){
			cin>>b>>c>>d;
			connect(b-1, c-1, d);
		}
		int m = maxflow (s-1, t-1, n);
		cout<<"Network "<<casos<<"\nThe bandwidth is "<<m<<".\n\n";
	}
	return 0;
}