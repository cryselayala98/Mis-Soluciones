#include <bits/stdc++.h>
using namespace std;

/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=216*/

int v, e; 
const int MAX=105; 
vector<int> ady[MAX]; 
bool marked[MAX]; 
int v_count;
void init(){
	for(int i = 0; i<=v; i++){
		ady[i].clear();
	}
}

static void dfs(int s){
	int i, next;

	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
		if( !marked[next] ){
			marked[next] = 1;
			v_count--;
			dfs(next);
		}	
	}
}

int main() {
	int a,b,c;
	while(cin>>v ,v){
		init();
		while(cin>>a,a){
			while(cin>>b,b){
				ady[a-1].push_back(b-1);
			}
		}
		cin>>a;
		while(a--){
			cin>>b;
			v_count=v;
			memset(marked, 0, sizeof(marked));
			dfs(b-1);
			cout<<v_count;
			for(int i = 0; i<v; i++) if(!marked[i])cout<<" "<<i+1;
			cout<<"\n";
		}
	}
	return 0;
}