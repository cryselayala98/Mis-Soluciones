#include <bits/stdc++.h>
using namespace std;

const int MAX_L = 10; 
char L = '0'; 

//https://www.spoj.com/problems/PHONELST/

struct node {
    int next[MAX_L];
    bool fin;
    node() {
        memset(next, -1, sizeof(next));
        fin = 0;
    }
};

vector<node> trie;

void init_trie() {
    trie.clear();
    trie.push_back(node());
}

int add_str(string s) {
    int cur = 0;
    for (auto c : s) {
        if (trie[cur].next[c-L] == -1) {
            trie[cur].next[c-L] = trie.size();
            trie.push_back(node());
        }
        cur = trie[cur].next[c-L];
    }
    trie[cur].fin = 1;
    return cur;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int t; cin>>t;
	
	while(t--){
		
		init_trie();
		vector<int> aux;
		
		int a; string b;
		cin>>a;
		while(a--){
		    cin>>b;
			int final = add_str(b);
			aux.push_back(final);
		}
		bool es = 1;
		for(int i = 0; i<aux.size(); i++){
			int f = aux[i];
			for(int i = 0; i<10; i++){
				if(trie[f].next[i]!=-1){
					es = 0;
					goto fin;
				}
			}
		}
		fin:
		if(es)cout<<"YES\n";
		else cout<<"NO\n";
		
	}
    
    
	return 0;
}