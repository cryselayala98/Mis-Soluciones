#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=701


string s;

const int N_MAX=1010;
int n;
int m;
int sa[N_MAX];
int rk[N_MAX];
long long rk2[N_MAX];

int lcp[N_MAX];

bool _cmp(int i, int j) {
  return rk2[i] < rk2[j];
}

void suffixArray() {
  for (int i = 0; i < n; i++) {
    sa[i] = i; rk[i] = s[i]; rk2[i] = 0;
  }
  for (int l = 1; l < n; l <<= 1) {
    for (int i = 0; i < n; i++) {
      rk2[i] = ((long long) rk[i] << 32) + (i + l < n ? rk[i + l] : -1);
    }
    sort(sa, sa + n, _cmp);
    for (int i = 0; i < n; i++) {
      if (i > 0 && rk2[sa[i]] == rk2[sa[i - 1]])
        rk[sa[i]] = rk[sa[i - 1]];
      else rk[sa[i]] = i;
    }
  }//cout<<"termino sa"<<endl;
}

void calculateLCP() {
  for (int i = 0; i < n; i++) rk[sa[i]] = i;
  for (int i = 0, l = 0; i < n; i++) {
    if (rk[i] > 0) {
      int j = sa[rk[i] - 1];
      while (s[i + l] == s[j + l]) l++;
      lcp[rk[i]] = l;
      if(l > 0) l--;
    }
  }
}

vector<pair<int, int>> longestCommonSubstring() {

  vector <pair<int, int>> comunes ;
  //cout<<n<<m<<endl;
  int lcs=-1;
  for (int i = 1; i < n; i++) {
      //  cout<<sa[i]<<endl;
  	if (((sa[i] < n - m - 1) != (sa[i - 1] < n - m - 1))  ) {
  	if(lcp[i] > lcs){
  	lcs = lcp[i];
  	comunes.clear();
  	comunes.push_back(make_pair(lcp[i], i));
  	}else if(lcp[i] == lcs){
  	comunes.push_back(make_pair(lcp[i], i));
  	}



    }
  }
  return comunes;
}


int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

string t1, t2;
cin>>t1>>t2;
string e;
bool b=false;
do{
	if(b){
	cout<<endl;
	}
getline(cin, e);
 m= t2.size();
 s=t1+"#"+t2+"$";
n= s.size();
//cout<<s<<endl;

 suffixArray();

 calculateLCP();

 vector <pair <int, int>> lcs = longestCommonSubstring();
//cout<<lcs.size()<<endl;
//cout<< lcs.first << " " << lcs.second <<" "<<sa[lcs.second]<< endl;
set<string> comunes;
int contavacios=0;

for(int i=0; i< lcs.size(); i++){
	string r=s.substr(sa[lcs[i].second], lcs[i].first);
	if(r.size()>0){

	comunes.insert(r);
	}else{
	contavacios++;
	}

}if(contavacios==lcs.size()){
cout<<"No common sequence."<<endl;
}else{
//	sort(comunes.begin(),comunes.end());
for(set<string>:: iterator it= comunes.begin(); it!= comunes.end(); it++){
cout<<*it<<endl;

}

}



b=true;
}while(cin>>t1>>t2);


return 0;}
