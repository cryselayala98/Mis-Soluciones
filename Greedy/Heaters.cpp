#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1066/problem/B

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n,r; cin>>n>>r;
	
	int house[n], p[n];
	for(int i = 0; i<n; i++){
		cin>>house[i]; p[i]= 0;
	}
	
	for(int i = 0; i<n; i++){ //prender todos los calentadores
		if(house[i]){ 
			int j = (i-(r-1)); int k = j + ((r-1)*2) + 1;
			
			for(; j<k; j++){
				if(j<0)continue;
				if(j==n)break;
				p[j]++;
			}
		}
	}
	
	bool es = 1; int cal = 0;
	for(int i = 0; i<n; i++){ //apagar innecesarias
		if(!p[i]){
			es = 0; break;
		}
		if(house[i]){ 
			cal++;
			int j = (i-(r-1)); int k = j + ((r-1)*2) + 1;
			bool v = 0;
			for(; j<k; j++){
				if(j<0)continue;
				if(j==n)break;
				if(p[j]==1){
					v = 1; break;
				}
			}
			
			if(!v){
				cal--;
			    j = (i-(r-1));
				for(; j<k; j++){
				if(j<0)continue;
				if(j==n)break;
				p[j]--;
			}
			}
		}
	}
	
	if(!es)cout<<-1<<endl;
	else cout<<cal<<endl;
	
	return 0;
}