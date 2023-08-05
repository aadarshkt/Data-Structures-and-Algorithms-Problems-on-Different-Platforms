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

    int t;
    cin >> t;
    while(t--){
        int n,m;cin>>n>>m;
        string s;cin>>s;
        vector<int> pre0(n),suf0(n),pre1(n),suf1(n);
        int cnt=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt=-1;
            else{
                if(cnt==-1)cnt=i;
            }
            pre0[i]=cnt;
        }
        cnt=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')cnt=-1;
            else{
                if(cnt==-1)cnt=i;
            }
            suf1[i]=cnt;
        }
        cnt=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')cnt=-1;
            else{
                if(cnt==-1)cnt=i;
            }
            suf0[i]=cnt;
        }
        cnt=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='0')cnt=-1;
            else{
                if(cnt==-1)cnt=i;
            }
            pre1[i]=cnt;
        }
        int fl=0;
        set<pair<int,int>> st;
        for(int i=0;i<m;i++){
            int l,r;cin>>l>>r;
            l--,r--;
            bool isSorted=false;
            if(l==r)isSorted=true;
            else{
                if(s[l]=='0'&&s[r]=='1'){
                    if(pre1[r]-suf0[l]==1)isSorted=true;
                }else if(s[l]=='0'&&s[r]=='0'){
                    if(suf0[l]>=r)isSorted=true;
                }else if(s[l]=='1'&&s[r]=='1'){
                    if(suf1[l]>=r)isSorted=true;
                }
            }
            if(isSorted){
                fl=1;
                continue;
            }
            int fr=l,se=r;
            if(l==0)fr=l;
            else{
                int ext=pre0[l-1];
                if(ext!=-1)fr=ext;
                else fr=l;
            }
            if(r==n-1)se=n-1;
            else{
                int ext=suf1[r+1];
                if(ext!=-1)se=ext;
                else se=r;
            }
            st.insert({fr,se});
        }
        dbg(st);
        int ans=(int)st.size();
        if(fl)ans++;
        cout<<ans<<'\n';
    }

    return 0;
}