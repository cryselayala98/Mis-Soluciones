#include <bits/stdc++.h>
using namespace std;

//http://trainingcenter.ufps.edu.co/clases/tarea/58/problema/301/292/es


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	set<pair<int, int> >vals;
	int a,b;
	while(cin>>a>>b){
		vals.insert(make_pair(a,b));
	}
	for(auto x: vals){
		cout<<x.first<<" "<<x.second<<endl;
	}
	return 0;
}