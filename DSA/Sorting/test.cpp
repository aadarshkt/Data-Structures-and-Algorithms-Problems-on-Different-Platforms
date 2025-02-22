#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> v={1};
            ans.push_back(v);
        }
        ans[1].push_back(1);
        for(int i=2;i<n;i++){
            for(int j=1;j<(int)ans[i-1].size();j++){
                ans[i].push_back(ans[i-1][j] + ans[i-1][j-1]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
  
int main() 
{ 
    vector<vector<int>> ans = generate(5);
    for(int i=0;i<(int)ans.size();i++){
        for(int j=0;j<(int)ans[i].size();j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0; 
} 
 