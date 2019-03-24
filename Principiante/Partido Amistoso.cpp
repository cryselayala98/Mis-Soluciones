#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int casos;
	cin>>casos;
int a,b;
	
	while(casos--){
		cin>>a>>b;
		if(a==b){
		cout<<"casi ganamos"<<endl;	
		}else if(a>b){
			cout<<"perdimos"<<endl;
		}else{
			cout<<"ganamos"<<endl;
		}
	}

	return 0;
}