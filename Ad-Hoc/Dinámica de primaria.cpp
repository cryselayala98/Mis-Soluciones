#include <bits/stdc++.h>
using namespace std;
 
//https://trainingcenter.cloud.ufps.edu.co/problemas/330/detalle/es
 
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
	int n, q; cin>>n>>q;
	
	map<string, int> vals;
	string str;
	getline(cin, str);
	for(int i = 0; i<n; i++){
		getline(cin, str);
		
		istringstream iss(str);
		string subs;
		string a ="";
		while (iss >> subs) {
			if(subs[0]-'0'>=0 && subs[0]-'0'<=9 ){
				vals[a] = stoi(subs);
			}else{
				a+=subs+" ";
			}
	}
	}
	while(q--){
		getline(cin, str);
		vector<string> h = split_char(str, '+');
		int acum=0;
		for(auto x : h){
			acum+= vals[x+" "];
		}
		cout<<acum<<endl;
	}
	
	
	return 0;
}
