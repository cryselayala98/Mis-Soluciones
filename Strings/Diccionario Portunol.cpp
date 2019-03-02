#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/100540/attachments ejercicio D

const int MAX_L = 26; 
char L = 'a'; 

struct node {
    int next[MAX_L];
    bool fin;
    node() {
        memset(next, -1, sizeof(next));
        fin = 0;
    }
};

vector<node> trie[2];
long long cont [2][26];

void init_trie() {
    trie[0].clear();
    trie[1].clear();
    trie[0].push_back(node());
    trie[1].push_back(node());
}

void add_str(string s, int a) {
    int cur = 0;
    for (int i = 0; i< s.size(); i++) {
		char c = s[i];
        if (trie[a][cur].next[c-L] == -1) {
            trie[a][cur].next[c-L] = trie[a].size();
            if(cur) cont[a][c-L]++;
            trie[a].push_back(node());
        }
        cur = trie[a][cur].next[c-L];
    }
    trie[a][cur].fin = 1;
}

int main() {
	
	
	ios::sync_with_stdio(0); cin.tie(NULL);
	int p,e; string a;
	while(cin>>p>>e, p){
		memset(cont, 0,sizeof(cont));
		init_trie();
		while(p--){
			cin>>a;
			add_str(a, 0);
		}
		while(e--){
			cin>>a;
			reverse(a.begin(), a.end());
			add_str(a, 1);
		}
		
		long long res = (trie[0].size()-1LL) * (trie[1].size()-1LL);
    	for(int i =0; i<26; i++)res-=cont[0][i]*cont[1][i];
    	cout<<res<<"\n";
	}
    
    return 0;
}

