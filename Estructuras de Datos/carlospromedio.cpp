#include <iostream>
using namespace std;

int main() {
	
int casos;
cin>>casos;
while(casos--){
	int num=0;
	int y;
	int suma=0;
	cin>>y;
	while(y!=0){
		num++;
		suma+=y;
		cin>>y;
	}
	cout<<suma/num<<" = "<<suma<<" / "<<num<<endl;
	
}
	return 0;
}