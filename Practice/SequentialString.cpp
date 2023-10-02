#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

vector<int> countMin(string s,vector<int> &m){
    int n=s.length(),n1=m.size();
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(!mp.count(s[i]-'0')){
            mp[s[i]-'0']=(i+1);
        }
    }
    vector<int> ans;
    for(int i=0;i<m.size();i++){
        int pos=-1;
        for(int j=0;j<(int)m[i].length();j++){
            if(mp.count(m[i][j]))pos=max(pos,mp[m[i][j]-'0']);
            else{
                pos=-1;break;
            }
        }
        ans.push_back(pos);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}