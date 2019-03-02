#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1015/problem/C

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	vector<long long> songs;
	
	int n,m; long long a,b;
	cin>>n>>m;
	long long acum = 0, acum2=0;
	while(n--){
		cin>>a>>b;
		songs.push_back(a-b);
		acum+= a; acum2+=b;
	}
	sort(songs.begin(), songs.end());
	
	if(acum2>m)cout<<-1<<endl;
	else if(acum<= m )cout<<0<<endl;
	else{
		int res = 0;
		for(int i = songs.size()-1; i>=0; i--){
			acum -= songs[i];
			res++;
			
			if(acum<=m)break;
		}
		cout<<res<<endl;
	}
	return 0;
}