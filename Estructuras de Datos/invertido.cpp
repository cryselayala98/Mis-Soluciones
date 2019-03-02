#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	string a;
	string b="";
	while(n--){
		cin>>a;
		b=a+"\n"+b;
	}
	cout<<b;
	return 0;
}