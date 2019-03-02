#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1003/problem/D

int pot[30];
  
int main() {
	
  ios::sync_with_stdio(0); cin.tie(NULL);
  int n, q; cin>>n>>q;
  int a; 
  
  while(n--){
  	cin>>a;
  	pot[(int)(log2(a))]++;
  }
  
  while(q--){
  	cin>>a;
  	int i = 29;
  	
  	int c = 0;
  	while(i>=0){
  	   int x= min(pot[i], a /(1<<i));
  	   c+=x;
  	   a-= x*(1<<i);
  	   i--;
  	}
  	
  	cout<<(a?-1:c)<<endl;
  }
  
  
	return 0;
}