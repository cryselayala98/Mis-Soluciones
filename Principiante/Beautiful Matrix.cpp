#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/263/A

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int x,y,a;
	
	for(int i =0; i<5; i++){
		for(int j =0; j<5; j++){
			cin>>a;
			if(a==1)x=i, y=j;
		}
	}
	cout<<abs(x-2)+abs(y-2)<<endl;
	return 0;
}