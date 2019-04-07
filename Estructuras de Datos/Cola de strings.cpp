#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	queue <string> s; string a;
	while(n--){
		cin>>a;
		if(a=="POP"){
			if(!s.empty()){
				cout<<s.front()<<"\n";
				s.pop();
			}else cout<<"-\n";
		}else{
			cin>>a;
			s.push(a);
		}
	}
	return 0;
}