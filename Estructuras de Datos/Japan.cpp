#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

//https://vjudge.net/problem/UVALive-2926


int main() {
	
	int t; cin>>t;
	int a,b,c,d,e;
	for(int i =1; i<=t; i++){
		cout<<"Test case "<<i<<": ";
		cin>>a>>b>>c;
		ordered_set arbol;
		set<pair<int, int> > pares;
		while(c--){
			cin>>d>>e;
			pares.insert(make_pair(d,e));
		}
		long long res=0;
		for(auto x : pares){
			res+= arbol.size() - arbol.order_of_key(make_pair(x.second, 10e9));
			arbol.insert(make_pair(x.second, x.first));
		}
		cout<<res<<endl;
	}
	return 0;
}