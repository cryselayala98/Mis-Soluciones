#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/302/detalle/es

char grid [11][11], g2[11][11];

vector<int> prefix_function(string s) {
	int n = s.size(), len = 0, i = 1;
	vector<int> lps(n);
	lps[len] = 0;
	while(i < n) {
		if(s[len] != s[i]) {
			if(len) len = lps[len-1];
			else lps[i++] = len;
		} else lps[i++] = ++len;
	}
	return lps;
}

int kmp(string cadena, string pattern) {
	int n=cadena.size();
	int m=pattern.size();
	vector<int> tab=prefix_function(pattern);

	for(int i = 0, seen = 0; i < n; i++) {
		while(seen > 0 && cadena[i] != pattern[seen]) {
			seen = tab[seen-1];
		}
		if(cadena[i] == pattern[seen]) seen++;
		if(seen == m) return i;
	}
	return -1;
}

int main() {
	int n,q;
	cin>>n>>q;
	string a;
	for(int i=0; i<n; i++){
		cin>>a;
		for(int j=0; j<n; j++){
			grid[j][i] =a[j];
			g2[j][i] =a[j];
		}
	}

	while(q--){
		cin>>a;
			int y = a.size();
//		cout<<"buscar "<<a<<endl;
		//de izq a der
		for(int i=0; i<n; i++){
			string b = "";
		for(int j=0; j<n; j++){
			b+=grid[i][j];
		}
		int pos = kmp(b,a);
		if(pos>-1){
			for(int j=pos; j>pos-y; j--)g2[i][j] = 'X';
		goto fin;
		}
	}
	
		//de arr a aba
		for(int j=0; j<n; j++){
			string b = "";
		for(int i=0; i<n; i++){
			b+=grid[i][j];
		}
		int pos = kmp(b,a);
		if(pos>-1){
			for(int i=pos; i>pos-y; i--)g2[i][j] = 'X';
			break;
		}
	}
	fin: int k =0;
	}
	
	for(int i =0; i<n; i++){
		for(int j =0; j<n; j++){
		if(g2[j][i]=='X'){
			cout<<grid[j][i];
		}else cout<<"X";
	}cout<<endl;
	}
	
	return 0;
}
            
