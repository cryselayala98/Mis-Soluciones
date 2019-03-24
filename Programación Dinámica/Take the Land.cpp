#include <bits/stdc++.h>
using namespace std;

//max range sum 2D
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1015

int land[105][105];

int y,x;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	while(cin>>y>>x, y){
		memset(land,0,sizeof(land));
		int t;
		for(int i=1;i<=y; i++){
			for(int j =1; j<=x; j++){
				cin>>t; t=!t; 
				land[i][j]= t+ land[i-1][j] + land[i][j-1] - land [i-1][j-1];
			}
		}
		int max_acum=0;
		for(int i=1;i<=y; i++){
			for(int j =1; j<=x; j++){
				int yy=y, xx=x;
				for(int k=i;k<=yy; k++){
					for(int l=j; l<=xx; l++){
						int r=land[k][l]-land[k][j-1]-land[i-1][l]+land[i-1][j-1];
						if(((k-i+1)*(l-j+1))==r)max_acum = max(max_acum, (r));
					}
				}	
			}
		}
		cout<<max_acum<<endl;
	}
	
	
	return 0;
}