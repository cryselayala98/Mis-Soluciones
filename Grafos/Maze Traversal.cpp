#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-10377

int maze[65][65];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t_c; cin>>t_c; int y,y1,x,x1; string a;
	char b;
	while(t_c--){
		cin>>y>>x;
		getline(cin,a);
		
		for(int i =0; i<y; i++){
			for(int j =0; j<x; j++){
				cin.get(b); a+= b;
				maze[i][j] = (b=='*');
			}
			cin.get(b);
		}
		cin>>y1>>x1; y1--; x1--;
		int d_x=0, d_y=-1;
		char D= 'N';
		while(cin>>a){
			for(int i = 0; i<a.size(); i++){
		
				if(a[i]=='Q') goto fin;
				
				if(a[i]=='F' && d_y+y1>=0 && d_x+x1>=0 && d_y+y1<y && d_x+x1<x){
			
					if(!maze[d_y+y1][d_x+x1])y1+= d_y, x1+= d_x;
			
					continue;
				}  
					swap(d_x, d_y);
					
					if(a[i]=='L' && !d_x) d_y*=-1;
					else if(a[i]=='R' && !d_y) d_x*=-1;
					
					if(d_y>0) D='S';
					else if(d_y<0) D='N';
					else if(d_x>0) D='E';
					else if(d_x<0) D='W';
					
			}
		}
		fin: cout<<y1+1<<" "<<x1+1<<" "<<D<<endl;
		if(t_c)cout<<endl;
		
	}
	
	return 0;
}