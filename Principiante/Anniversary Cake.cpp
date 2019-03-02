#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

//https://codeforces.com/gym/101142 ejercicio a



int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("anniversary.in", "r", stdin);
  freopen("anniversary.out", "w", stdout);


	int w,h,ax,ay,bx,by;
	cin>>w>>h>>ax>>ay>>bx>>by;
	
	vector <pair<int, int>> p;
	
	p.push_back(make_pair(ax,ay));
	p.push_back(make_pair(bx,by));

	sort(p.begin(), p.end());
	
	if(p[0].s >= p[1].s){
		cout<<p[0].f<<" "<<0<<" "<<p[1].f<<" "<<h<<endl;
	}else{
		cout<<0<<" "<<p[0].s<<" "<<w<<" "<<p[1].s<<endl;
	}
		
		
	
	
	
	
	return 0;
}