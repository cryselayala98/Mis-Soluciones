#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/even-and-odd-elements-at-even-and-odd-positions/0
int main() {
	int casos, a,b;
	cin>>casos;
	int arr[100010];
	while(casos--){
		cin>>a;
		memset(arr, 0, sizeof(arr));
		int par=-2, impar =-1; 
		for(int i=0; i<a; i++) {
			cin>>b;
			if(b%2 == 0) par+=2, arr[par] = b;
			else	 impar+=2, arr[impar] = b;
		}
		int cont =0;
		for(int i = 0; cont<a; i++){
			if(i>0 && arr[i]!=0)cout<<" ";
			if(arr[i]!=0){cout<<arr[i]; cont++;}
		}
		cout<<endl;
	}
	return 0;
}