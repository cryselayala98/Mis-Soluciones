#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-231

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	vector<int>vals;
	int a;
	int t=1;
	while(cin>>a && a!=-1){
		if(t>1)cout<<endl;
		vals.push_back(a);
		while(cin>>a && a!=-1){
			vals.push_back(a);
		}
		//Longest decreasing subsequence
		int memo[vals.size()]; 
		int maxi =0;
		for(int i =0; i<vals.size(); i++){
			memo[i]=1;
			for(int j =0; j<i; j++){
				if(vals[j]>=vals[i])memo[i]= max(memo[i], memo[j]+1);
		 }	
		 maxi= max(memo[i], maxi);
		}
		cout<<"Test #"<<t<<":\n  maximum possible interceptions: ";
		cout<<maxi<<endl;
		t++;
	
		vals.clear();
	}
	
	return 0;
}