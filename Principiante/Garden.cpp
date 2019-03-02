#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/915/problem/A

int main() {
	// your code goes here
	int cubos, largo;
	cin>>cubos>>largo;
	int min=200;
	int cubo;
	while(cubos--){
	cin>>cubo;
	if(largo%cubo==0){
	if(largo/cubo < min){
		min= largo/cubo;
	}
	}
	}
	cout<<min<<endl;
}