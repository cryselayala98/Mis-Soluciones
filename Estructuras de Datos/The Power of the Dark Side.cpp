#include <bits/stdc++.h>
using namespace std;
#define jedi pair <int, pair<int, pair<int, int> > > //ordenar a>b>c y insertar el indice donde se inserta el nuevo jedi
#define max -2e9
#define mp make_pair
#define f first
#define s second

//https://codeforces.com/gym/100247/problem/A

set<jedi> tournament;
vector<pair<int, int> > s_do, t_rd; //val, ind
int a[3];
	
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; cin>>n;

	int i = 0;
	while(n--){
		cin>>a[0]>>a[1]>>a[2];
		sort(a, a+3);
		tournament.insert(mp(a[2], mp(a[1], mp(a[0], i))));
		
		s_do.push_back(mp(a[1], i));
		t_rd.push_back(mp(a[0], i));
		
		i++;
	}
	
	sort(s_do.rbegin(), s_do.rend());
	sort(t_rd.rbegin(), t_rd.rend());
	
	int cont = 0; vector<int>res;
		
	int b = s_do[0].s, c = t_rd[0].s;
	for(auto x : tournament){
		int r = 0;
		if(b==x.s.s.s) r++;
		else if(b!=x.s.s.s && x.f>s_do[0].f) r++;
		
		if(c==x.s.s.s) r++;
		else if(c!=x.s.s.s && x.s.f>t_rd[0].f) r++;
		
		if(r==2){
			cont++;
			res.push_back(x.s.s.s + 1);	
		}
	}

	cout<<cont<<endl;
	sort(res.begin(), res.end());
	for(i = 0; i<res.size(); i++){
		if(i)cout<<" ";
		cout<<res[i];
	}cout<<endl;
	
	return 0;
}