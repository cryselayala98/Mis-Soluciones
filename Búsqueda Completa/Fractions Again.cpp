#include <bits/stdc++.h>
using namespace std;
/*uva.onlinejudge.orgindex.phpoption=com_onlinejudge&Itemid=8&page=show_problem&problem=1917*/

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int h;
	while(cin>>h){
		vector <pair <int,int>> res;
		int cont = 0;
		for(int i = h+1; i<=h*2; i++){
				int num = i-h;
				int den = i*h;
				if(den%num == 0){
					res.push_back(make_pair(den/num,i));
					cont++;
					}
		}
		
		cout<<res.size()<<"\n";
		for(int i = 0 ; i<res.size(); i++){
			cout<<"1/"<<h<<" = 1/"<<res[i].first<<" + 1/"<<res[i].second<<"\n";
		}
	}
	return 0;
}