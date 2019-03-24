#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000

//http://trainingcenter.ufps.edu.co/clases/tarea/51/problema/284/246/es

int memo[1005][1005];
int valor[1005];
int costo[1005];
int n,m, n_libros, total_libros;

int dp(int idx, int k){
	if(k<0)return -inf;
	if(idx>=total_libros) return 0;
	if(memo[idx][k]!=-1) return memo[idx][k];
	
	return memo[idx][k] = max(dp(idx+1, k), dp(idx+1, k-costo[idx]) + valor[idx]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int t;cin>>t;
	while(t--){
		cin>>m>>n;
		memset(memo, -1, sizeof(memo));
		int i = 0;
		total_libros=0;
		while(n--){
			cin>>n_libros;
			
			for(int j = total_libros; j<total_libros+n_libros; j++){
				cin>>costo[j];
			}
			for(int j = total_libros; j<total_libros+n_libros; j++){
				cin>>valor[j];
			}
			total_libros+=n_libros;
		}
		cout<<dp(0, m)<<endl;
	}
	
	return 0;
}