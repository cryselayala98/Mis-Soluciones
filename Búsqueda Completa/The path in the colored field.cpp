#include <bits/stdc++.h>
using namespace std;
#define celda pair <int, int>
#define f first
#define s second
#define add(i,j) push_back(make_pair(i,j))

/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1043*/

vector <celda> n1,n3;

int main() {
	int n; string a;
	
	while(cin>>n){
		n1.clear(); n3.clear();
		int i = 0;
		while(i<n){
			cin>>a;
			for(int j = 0; j<a.size(); j++){
				if(a[j]=='1') n1.add(i,j);
				if(a[j]=='3') n3.add(i,j);
			}
		i++;
		}
		int min_d = 10e8, max_d = 0;
		
		for(int i = 0; i<n1.size(); i++){
			for(int j = 0; j<n3.size(); j++){
				min_d = min(min_d, ((max(n1[i].f, n3[j].f) - min(n1[i].f, n3[j].f)) + (max(n1[i].s, n3[j].s) - min(n1[i].s, n3[j].s))));
			}
			max_d = max(max_d, min_d);
			min_d = 10e8;
		}
		cout<<max_d<<"\n";
	}
	return 0;
}