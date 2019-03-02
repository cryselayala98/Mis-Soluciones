#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101972/problem/F

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int c; vector<int> vals;
	cin>>c;
	while(c--){
		vals.clear();
		for(int i =0; i<26; i++){
			int a; cin>>a; if(a>0)vals.push_back(a);
		}
		sort(vals.begin(), vals.end());
		int p_max=0, max_list= INT_MAX;
	
		if(vals.empty()) max_list= 0;
		else{
		for(int i = vals.size()-1; i>=0; i--){
			int x = vals[i];
			if(x>=2){
				p_max+=2; max_list = min(max_list, x/2);
			}else if(x==1){
				p_max+=1;
				max_list= min(max_list, (i+1));
				break;
			}
		}
		}
		cout<<p_max<<" "<<max_list<<"\n";
	}
	return 0;
}