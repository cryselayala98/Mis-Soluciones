#include <bits/stdc++.h>
using namespace std;

// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2737

/*recorrido en grafos, donde debo recorrer todas los subgrafos conexos del grafo total y decir si en cada subgrafo hay un balanceo (el total debe dar 0 cada vez que invoque el dfs)*/

int total;

int v, e; 
const int MAX=100005; 
vector<int> ady[MAX]; 
bool marked[MAX]; 
int plata[MAX];

void init(){
for( int j = 0; j <= v; j++ ) {
        total=0;

        ady[j].clear(); 
        marked[j] = 0; 
    }
}


void dfs(int s) {

	total+=plata[s];
	marked[s] = 1;
	int i, next;

	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
		if( !marked[next] ){	dfs(next);}
	}
}


int main() {

ios_base::sync_with_stdio(false);
cin.tie(NULL);

int casos,  p, a1, a2;
cin >> casos;
while(casos--){
	cin>>v>>e;

	int i=0;
	while(i<v){
		cin>>p;

		plata[i]=p;
		i++;
	}//cout<<re.size()<<endl;
	i=e;
	while(i--){
		cin>> a1>>a2;
		ady[a1].push_back(a2);
		ady[a2].push_back(a1);
	}


bool posible=true;
int j=0;
while(j<v){
      if(!marked[j]){
	dfs(j);
	//cout<<total<<endl;
	if(total!=0){
	posible =false; break;}
}
j++;

}

if(posible){
	cout<<"POSSIBLE"<<endl;
}else{
	cout<<"IMPOSSIBLE"<<endl;
}
init();

}
	return 0;
}
