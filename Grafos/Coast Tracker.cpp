#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-824

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int x[]={-1,-1,0,1,1,1,0,-1};
	int y[]={0,-1,-1,-1,0,1,1,1};
	int a,b,cc;
	cin>>a;
	while(a>-1){
		cin>>b>>cc;
		bool cuadro[3][3];
		int r=-1;
		int d,e,w;
		for(int i =0;i<8; i++){
			cin>>d>>e>>w;
			int f =1, c=1;
		
			if(d>a)c++; if(d<a)c--;
			if(b>e)f++; if(b<e)f--;
		
			cuadro[f][c] = w;
		}
		for(int i =0;i<8; i++){
			if(cuadro[1+x[(i+cc+5)%8]][1+y[(i+cc+5)%8]]) {
				r= (i+cc+5)%8 ; break;
			}
		}
		cout<<r<<endl;
		cin>>a;
	}
	return 0;
}