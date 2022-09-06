#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(...) 42
#endif
vector<vector<string>> pth(1001,vector<string>(1001,""));
vector<string > s;
int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
char mv[4]{'R','L','U','D'};
int n,m;
bool inrange(int i,int j){
	if(i<0 || i>=n || j<0 || j>=m) return false;
	return true;	
}
vector<vector<bool>> vis(1001,vector<bool> (1001,false));
void bfs(int i,int j){
	// now we call bfs for all the child in the array
	queue<pair<int,int>> q;
	q.push({i,j});
	while(!q.empty()){
		pair<int,int> node=q.front();
		q.pop();
		if(s[node.first][node.second]=='B') return ;
		if (vis[i][j]) continue;
		vis[i][j]=true;
		for(int k=0;k<4;k++){
			int x=node.first-dx[k];
			int y=node.second - dy[k];
			debug(x,y,node);
			if(inrange(x,y)){
				 if(s[x][y]=='.'){
				 	q.push({x,y});
					debug(q.size());
				 	pth[x][y]=pth[node.first][node.second]+mv[k];
				 }
			}
		}
	}
}
int32_t main(){

	cin>> n>> m;

	for(int i=0;i<n;i++){
		string x;
		cin>> x;
		s.push_back(x);
	}
	debug(s);
	pair<int,int> end;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='A'){
				debug("A",i,j);	
				bfs(i,j);
			}
			if(s[i][j]=='B'){
				end={i,j};
			}
		}
	}
	cout<<pth[end.first][end.second]<<endl; 

	return 0;
	
}