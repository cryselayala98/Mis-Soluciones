#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos, a,b,d; string c,e;
	queue <string> f1, f2;
	cin>>casos;
	while(casos--){
		cin>>a>>b;
		while(a--){
			cin>>c;
			f1.push(c);
		}
		while(b--){
			cin>>d;
			if(d==1 && !f1.empty()) {
				f2.push(f1.front());
				f1.pop();
			}else if(d==2 && !f2.empty()){
				f1.push(f2.front());
				f2.pop();
			}
		}
		if(f1.empty())cout<<"-"<<"\n";
		else{
			bool v = 0;
			while(!f1.empty()){
				if(v)cout<<" ";
				v = 1;
				cout<<f1.front();
				f1.pop();
			} cout<<"\n";
		}
		if(f2.empty())cout<<"-"<<"\n";
		else{
			bool v = 0;
			while(!f2.empty()){
				if(v)cout<<" ";
				v = 1;
				cout<<f2.front();
				f2.pop();
			} cout<<"\n";
		}
	}
	return 0;
}