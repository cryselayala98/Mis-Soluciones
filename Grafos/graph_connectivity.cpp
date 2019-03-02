#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400

int v; 
const int MAX=1000;
vector<int> ady[MAX]; 
bool marked[MAX]; 


static void dfs(int s){
	marked[s] = 1;
	int i, next;

	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
		if( !marked[next] )	dfs(next);
	}
}


int main() {
	int casos; string a; string s;
	cin>>casos; getline(cin,s); getline(cin,s); 
	while(casos--){
		getline(cin, a); 
		v= a[0]-64; 
		/*clear*/
		for(int i=0; i<v; i++){
			marked[i]=false;
			ady[i].clear();
		}
		
		getline(cin, s);
		while(s != ""){
			int c= s[0]-65;
			int d= s[1]-65;
			
			ady[c].push_back(d);
			ady[d].push_back(c);
			getline(cin, s);
		}
		
		int connected=0;
		for(int i=0; i<v; i++) if(!marked[i]) connected++, dfs(i);
		cout<<connected<<"\n";
		if(casos>0) cout<<"\n";
		
		
	}

	return 0;
}