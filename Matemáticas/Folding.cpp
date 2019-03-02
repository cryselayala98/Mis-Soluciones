#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101142 ejercicio f

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);

	int w,h,ww,hh; cin>>w>>h>>ww>>hh;
	int w1 = w,h1=h, ww1 =hh, hh1=ww;
	
	if((ww<=w && hh<=h) ||(ww1<=w1 && hh1<=h1)){
		
	int cont = 0, cont2 = 0;
	while(w > ww){
		w = (w+1) / 2; cont ++;
	} 
		
	while(h >hh){
		h = (h+1) / 2; cont ++;
	}
	
	while(w1 > ww1){
		w1 = (w1+1) / 2; cont2 ++;
	} 
		
	while(h1 >hh1){
		h1 = (h1+1) / 2; cont2 ++;
	}
	cout<<min(cont,cont2)<<endl;
		
	}else cout<<-1<<endl;
	
	return 0;
}