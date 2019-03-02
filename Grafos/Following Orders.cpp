#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-124
//grafos + backtracking

int n;
map<char, vector<char>> ady;
set<char> el;
bool marked[125]; 

void backtrack(string a, int cont){
	if(cont == n) cout<<a<<endl;
	
	for(char z : el){
		if(!marked[z]){
			marked[z] = 1;
			
			bool nvv = 0;  //validar que no haya visitado vecinos antes
			for(char aux : ady[z]){
				if(marked[aux]){
					nvv = 1;
					break;
				}
			}
			
			if(!nvv) backtrack(a+z, cont+1);
			
			marked[z] = 0;
		}
	}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	string a;
	
	int caso = 0; 
	while(getline(cin, a)){
		if(caso)cout<<endl;
		n = a.size() - (a.size()/2); 
		memset(marked,0,sizeof(marked));
		ady.clear(); el.clear();
		for(int i = 0; i< a.size(); i+=2) el.insert(a[i]);
		
		getline(cin, a);
		
		istringstream iss(a);
		string b,c; int i = 0;
		while (iss >> b >> c) {
			ady[b[0]].push_back(c[0]);
		}
		
		backtrack("", 0);
		caso++;
	
	}
	

	return 0;
}