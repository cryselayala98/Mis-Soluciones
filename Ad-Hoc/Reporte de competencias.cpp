#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/317/detalle/es

vector<string> split_char (string str, char delim) {
    vector<string> split;
    istringstream iss(str);
    string sub_str;
    while(getline(iss, sub_str, delim)){
        split.push_back(sub_str);
    }
    return split;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n;
	while( cin>>n){
	map<string,string>id;
	multiset<pair<int, string>> eq;
	while(n--){
		string a; 
		cin>>a;
		vector<string>b = split_char(a, ';');
		vector<string>c = split_char(b[0], '>');
		string g = c[1];
		int v = stoi(g);
		for(int i = 1; i<b.size(); i++){
			g = b[i];
			v+= stoi(g);
		}
		v*=-1;
		string f = c[0].substr(0, c[0].size()-1);
		g="";
		for(int i = 0; i<f.size(); i++)g+=tolower(f[i]);
		id[g] = f;
		eq.insert(make_pair(v,g));
	}
	for(auto x: eq){
		int v = x.first;
		cout<<id[x.second]<<" "<<v*-1<<endl;
	}
	}
	return 0;
}
