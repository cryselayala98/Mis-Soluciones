#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

//http://codeforces.com/contest/1077/problem/C

int main() {
	int n ; cin>>n;
	unsigned long long suma[n]; vector<pair<int, int> > arr; vector<int> arr2;
	unsigned long long acum =0;
	int a;
	for(int i =0; i<n; i++){
		cin>>a; arr.push_back(make_pair(a,i+1)); arr2.push_back(a);
	}
	sort(arr.begin(), arr.end()); sort(arr2.begin(), arr2.end());
	for(int i =0; i<n; i++){
		acum+=arr2[i];
		suma[i] = acum;
	}
	set<int> good;
	for(int i =0; i<n; i++){
		int aux= arr2[i];
		arr2[i] = -1;
		
		//lados
		 acum=0;
		
		if(i==0)acum =suma[n-1] - suma[i];
		else acum = suma[i-1] + (suma[n-1] - suma[i]);
		//cout<<acum<<endl;
		if(!(acum%2)){
			long long mit= acum/2;
			if(binary_search(arr2.begin(), arr2.begin()+i, mit) || binary_search(arr2.begin()+i, arr2.end(), mit)){
			good.insert(arr[i].s);	
			} 
		}
		
		arr2[i]= aux;
	}
	cout<<good.size()<<endl;
	bool y = 0;
	for(auto z : good){
		if(y)cout<<" ";
		y =1;
		cout<<z;
	}
	if(good.size()>0)cout<<endl;
	
	return 0;
}