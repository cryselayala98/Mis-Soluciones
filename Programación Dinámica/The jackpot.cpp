#include <bits/stdc++.h>
using namespace std;

//max range sum
//https://vjudge.net/problem/UVA-10684

long long arr[10005]; long long memo[10005];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int a;
	while(cin>>a,a){
		for(int i = 0; i<a; i++)cin>>arr[i];
		
		long long best =-1000000000000000; long long sum=0;
		for(int i = 0; i<a; i++){
			sum+= arr[i];
			best = max(best, sum);
			memo[i]=best;
			if(sum<0)sum=0;
		}
		if(memo[a-1]<=0)cout<<"Losing streak."<<endl;
		else cout<<"The maximum winning streak is "<<memo[a-1]<<"."<<endl;
	}
	return 0;
}