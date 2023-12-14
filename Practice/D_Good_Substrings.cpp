#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;cin>>s;
    int n=s.length();
    string gs;cin>>gs;
    int k;cin>>k;
    map<int,int> mp;
    for(int i=0;i<26;i++){
        mp[i]='1'-gs[i];
    }
    vector<int> pre(n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=mp[s[i]-'a'];
        pre[i]=sum;
    }
    dbg(mp);
    dbg(pre);
    int ans=0;
    set<string> st;
    for(int i=0;i<n;i++){
        string str;
        for(int j=i;j<n;j++){
            str.push_back(s[j]);
            int cnt=pre[j];
            if(i>0)cnt-=pre[i-1];
            if(cnt<=k&&!st.count(str)){
                ans++;
                st.insert(str);
            }
        }
    }
    dbg(st);
    cout<<ans<<'\n';

    return 0;
}