#include <bits/stdc++.h>
using namespace std;
//http://trainingcenter.ufps.edu.co/problemas/296/detalle/en

long long binarySearch(int l, int r, long long x){ 
   if (r >= l){ 
        long long mid = l + (r - l)/2; 
        long long val = (mid * (mid+1))/2;
        long long ant = val-mid;
        if (val== x || (x>ant && x<val)) return mid; 
        if (val > x)    return binarySearch(l, mid-1, x); 
        return binarySearch(mid+1, r, x); 
   } 
   return -1; 
} 

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	//precalcular
	vector<long long> nums;
	long long ans, i=0; 
	for(i; i<1500000; i++){
		ans = (i*(i+1)*(2*i+1))/6;
		nums.push_back(ans);
	}
	int casos; long long n;
	cin>>casos;
	
	while(casos--){
		cin>>n;
		long long i = lower_bound(nums.begin(), nums.end(), n)-nums.begin();
		long long ac = (i*(i+1)*((2*i)+1))/6;
		if(ac == n)cout<<i*i<<"\n";
		else{
		ac -= i*i; //irme a val antes;
		long long mitad = ac+((i*(i+1))/2);
		if(n<= mitad){
			long long pos = binarySearch(1, i, n-ac);
			cout<<((i-1)*(i-1))+pos<<endl;
		}else{
		long long sig = ac+ (i*i); 
			ac = mitad;
			long long pos = binarySearch(1, i-1, ((i*(i-1))/2)-(n-ac)+1);
			cout<<((i-1)*(i-1))+i+(i-pos)<<endl;
		}
		
		}
	}
	
	
	return 0;
}