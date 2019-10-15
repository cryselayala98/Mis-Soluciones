#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

//http://trainingcenter.cloud.ufps.edu.co/clases/tarea/58/problema/303/294/es

double euclideanDistance(double x1, double y1, double x2, double y2){           
  return hypot(x1 - x2, y1 - y2); 
} 

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n,k,t; double r,a,b;
	cin>>t;
	while(t--){
		cin>>n>>k>>r;
		
		vector<pair<double, double> > sillas;
		
		for(int i =0; i<n; i++){
			cin>>a>>b;
			sillas.push_back(make_pair(a,b));
		}
		
		int maxi=0; double x,y; 
		for(int i = 0; i<k; i++){ //puntos router
			cin>>a>>b;
			int cnt=0;
			//evaluar puntos que cubre el area
			for(auto x: sillas){
				double dist = euclideanDistance(x.f,x.s, a,b);
				if(dist<=r)cnt++;
			}
			if(cnt>maxi){
				maxi=cnt; 
				x=a; y=b;
			}
		}
		cout<<x<<" "<<y<<" "<<maxi<<endl;
	}
	return 0;
}
