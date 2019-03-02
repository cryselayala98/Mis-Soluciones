#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/contest/279190?fbclid=IwAR1prf92xWiF4gOb-xyx9-QtT8jfhf_ZtAIH48cXFNu3mFJyL68hDvyuPQg#problem/A

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n,m; cin>>n>>m;
	vector<pair<int, int> > cajas; //coincidencias, num cajas
	while(m--){
		int a,b; cin>>a>>b;
		cajas.push_back(make_pair(b,a));
	}
	sort(cajas.rbegin(), cajas.rend());
	int maxi_c=0;
	
	for(int i =0; i<cajas.size() && n>0; i++){
		int a= cajas[i].first; int b= cajas[i].second;
		int resto ;
		if(n>=b)resto=b, n-=b;
		else resto=n, n=0;
		
		maxi_c += resto*a;
	}
	cout<<maxi_c<<endl;
	return 0;
}