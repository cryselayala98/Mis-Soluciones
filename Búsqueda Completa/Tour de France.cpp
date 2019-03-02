#include <bits/stdc++.h>
using namespace std;
/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2183*/

vector <double> dl, tr, ra;

int main() {
	int n,m; double a;
	while(cin>>m, m){
		cin>>n;
		dl.clear(); tr.clear(); ra.clear();
		
		while(m--){
			cin>>a;
			dl.push_back(a);
		}
		while(n--){
			cin>>a;
			tr.push_back(a);
		}
			for(int i =0; i<tr.size(); i++){
				for(int j =0; j<dl.size(); j++){
					ra.push_back(tr[i] / dl[j] );
				}
			}
			double maxx = 0.0;
			sort(ra.begin(), ra.end());
			for(int i = 0; i<ra.size()-1; i++){
				maxx = max(maxx, ra[i+1] / ra[i] );
			}
			
			cout<<fixed<<setprecision(2)<<maxx<<"\n";
		
		
	}
	return 0;
}