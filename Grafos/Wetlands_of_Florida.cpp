#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410
const int tam = 1000; 
int dy[] = {1,1,0,-1,-1,-1, 0, 1}; 
int dx[] = {0,1,1, 1, 0,-1,-1,-1}; 
int grid[tam][tam]; 
int X, Y; 



int floodfill(int y, int x, int c1, int c2) { 
	if (y < 0 || y >= Y || x < 0 || x >= X) return 0;
	
	if (grid[y][x] != c1) return 0; 
	
	int ans = 1; 
	grid[y][x] = c2; 
	
	for (int i = 0; i < 8; i++)
		ans += floodfill(y + dy[i], x + dx[i], c1, c2);
	
	return ans;
}

int main() {
	int casos; string s;
	cin>>casos; getline(cin, s);
	getline(cin, s);
	while(casos--){
		getline(cin, s);
		X= s.size();
		Y=0;
		while(s[0]=='L' || s[0]=='W'){
			Y++;		
			for(int i=0; i<X; i++){ 
				if(s[i]=='L')grid[Y-1][i] = -1;//L
				else         grid[Y-1][i] = -2;//W
				}
			getline(cin,s);
		} 
	
		while(s!=""){
			istringstream iss(s);
			int subs; 
			vector<int> nums;
			while (iss >> subs) {
				nums.push_back(subs);
			
			} 
			if(grid[nums[0]-1][nums[1]-1] != -2){
				cout<<grid[nums[0]-1][nums[1]-1]<<"\n";
			}else{
			int res = floodfill(nums[0]-1, nums[1]-1, -2, 0);
			          floodfill(nums[0]-1, nums[1]-1,  0, res);
			cout<<res<<"\n";
			}
			getline(cin, s);
		}
		if(casos>0)cout<<"\n";
	}
	return 0;
}
