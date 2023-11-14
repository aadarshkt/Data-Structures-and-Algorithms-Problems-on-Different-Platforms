#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

string printMinNumberForPattern(string s){
    // code here 
    int n=s.length();
    int p=1;
    dbg(s);
    string ans="";
    for(int i=0;i<n;i++){
        if(s[i]=='I'){
            ans.push_back(p+'0');
            p++;
        }else{
            if(!ans.empty())ans.pop_back();
            p++;
            ans.push_back('0'+p);
            ans.push_back(p-1+'0');
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s="D";
    cout<<printMinNumberForPattern(s)<<'\n';

    return 0;
}