#include <bits/stdc++.h>
using namespace std;

//https://www.urionlinejudge.com.br/judge/es/problems/view/1527

const int MAX = 100005; 
int dsu[MAX]; 
int size[MAX]; 
int numSets; 

void init(int n) {
	numSets = n;
	for(int i = 0; i < n; i++) {
		dsu[i] = i; cin>>size[i];
	}
}

int find(int i) {
	return (dsu[i] == i) ? i : (dsu[i] = find(dsu[i]));
}

void unite(int a, int b) {
	a = find(a); b = find(b);
	if(a == b) return;
	if (size[a] > size[b]) swap(a, b);
	dsu[a] = b;
	size[b] += size[a];
	numSets--;
}

int sizeOf(int i) { return size[find(i)]; }

int main() {
	int n,q;
	while(cin>>n>>q, n+q){
		init(n);
		int a,b,c;
		int win=0;
		while(q--){
			cin>>a>>b>>c;
			if(a==1)unite(b-1,c-1);
			else{
				int sb=sizeOf(b-1);
				int sc=sizeOf(c-1);
				
				if(sb>sc && find(b-1)==find(0))win++;
				else if(sb<sc && find(c-1)==find(0))win++;
			}
		}
		cout<<win<<endl;
	}
	return 0;
}