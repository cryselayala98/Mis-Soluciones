#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101972/problem/G

int main() {
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c; int I, J;
	long long cuadrante [503][503][4]; // hallar max de cada mov en los cuadrantes
	long long matriz [502][502]; 
	long long c_aux [500];
	cin>>c;
	
	while(c--){
		cin>>I>>J;
		for(int i =0; i<I; i++){
			for(int j=0; j<J; j++){
				cin>>matriz[i][j];
			
			}
		}
		//cuadrante 1
		for(int i =1; i<I-1; i++){
			for(int j=1; j<J-1; j++){
				if(j-1==0) cuadrante[i][j-1][0]= 0;
				if(i-1==0) cuadrante[i-1][j][0] =0;
				cuadrante[i][j][0] = max (matriz[i-1][j-1], max(cuadrante[i][j-1][0], cuadrante[i-1][j][0]));
			
			}
		}
		
		//cuadrante 2
		for(int i =1; i<I-1; i++){
			for(int j=J; j>2; j--){
				if(j==J) cuadrante[i][j+1][1]= 0;
				if(i-1==0) cuadrante[i-1][j][1] =0;
				cuadrante[i][j][1] = max (matriz[i-1][j-1], max(cuadrante[i][j+1][1], cuadrante[i-1][j][1]));
				
			}
		}
		
		//cuadrante 3
		for(int i =I; i>2; i--){
			for(int j=1; j<J-1; j++){
				if(j-1==0) cuadrante[i][j-1][2]= 0;
				if(i==I) cuadrante[i+1][j][2] =0;
				cuadrante[i][j][2] = max (matriz[i-1][j-1], max(cuadrante[i][j-1][2], cuadrante[i+1][j][2]));
		
			}
		}
		
		//cuadrante 4
		for(int i =I; i>2; i--){
			for(int j=J; j>2; j--){
				if(j==J) cuadrante[i][j+1][3]= 0;
				if(i==I) cuadrante[i+1][j][3] =0;
				cuadrante[i][j][3] = max (matriz[i-1][j-1], max(cuadrante[i][j+1][3], cuadrante[i+1][j][3]));
			}
		}
		
		long long mini= 10e11, maxi=0, dif= 10e11;
		for(int i =1; i<I-1; i++){
			for(int j=1; j<J-1; j++){
					mini =10e11; maxi=0;
					int ii=i,jj=j;
					
					mini = min(mini, cuadrante[ii][jj][0]);
					maxi = max(maxi, cuadrante[ii][jj][0]);
					jj+=2;
					mini = min(mini, cuadrante[ii][jj][1]);
					maxi = max(maxi, cuadrante[ii][jj][1]);
					ii+=2; jj-=2;
					mini = min(mini, cuadrante[ii][jj][2]);
					maxi = max(maxi, cuadrante[ii][jj][2]);
					jj+=2;
					mini = min(mini, cuadrante[ii][jj][3]);
					maxi = max(maxi, cuadrante[ii][jj][3]);
					
					dif = min(dif, abs(mini-maxi));
			}
		}
		cout<<dif<<endl;
	}
	
	return 0;
}