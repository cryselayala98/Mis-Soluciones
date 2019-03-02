#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/237999/problem/B

int memo[86405];

vector<int> split_char (string str, char delim) {
    vector<int> split;
    istringstream iss(str);
    string sub_str;
    while(getline(iss, sub_str, delim)){
        split.push_back(stoi(sub_str));
    }
    return split;
}

void precalculo(){
	int i = 0;
	memo[0] = 0;
	for(int h= 0; h<24; h++){
		int op ;
		
		if(h%10<6){
			string o = to_string(h);
			reverse(o.begin(), o.end());
			if (o.size()==1)o+="0";
			op = stoi(o);
			}
		for(int m = 0; m<60; m++){
			for(int s = 0; s<60; s++){
				i++; //if(i == 100) return;
				if(i==1)memo[i]=1;
				else{
					memo[i] = memo[i-1];
					if(m%11 == 0 && h%10<6){
						if(op==s)memo[i]++;
					}
				}
				
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	precalculo();
	int c;cin>>c;
	string a,b;
	while(c--){
		cin>>a>>b;
		vector<int>a1 = split_char (a,':');
		vector<int>b1 = split_char (b,':');
		int seg_a = (a1[0]*3600) + (a1[1]*60) + a1[2] + 1;
		int seg_b = (b1[0]*3600) + (b1[1]*60) + b1[2] + 1;
	
		cout<<(memo[seg_b] - memo[seg_a-1])<<endl;
	}

	return 0;
}
