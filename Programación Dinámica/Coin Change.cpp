#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=615

int coins[] = {50,25,10,5,1};
long long ways[10005];
int N;

void dp(){
	ways[0] = 1;
	for(int i = 0; i<5; i++){
		for(int j = coins[i]; j< 10005; j++){
			ways[j] += ways[j-coins[i]]; //acumular el precalculado las formas de combinar para ways[j]-coins[i]
		}
	}
	
}


int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	memset(ways, 0, sizeof(ways));
	dp();
	
	while(cin>>N){
		cout<<ways[N]<<endl;
	}
		
}