#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void cleanUp(string &s,int n){
    for(int i=0;i<n;i++){
        if(s[i]=='?')s[i]='a';
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s,t;cin>>s>>t;
    int n=s.length(),m=t.length();
    int cntq=0;
    map<char,int> a,b;
    for(int i=0;i<m;i++){
        b[t[i]]++;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='?')cntq++;
        else a[s[i]]++;
    }
    int lo=-1,hi=(n/m)+1;
    while(hi-lo>1){
        int mid=lo+(hi-lo)/2;
        int localQ=0;
        for(auto x:b){
            int ch=x.first,fr=x.second;
            int frs=a[ch];
            int req=fr*mid;
            if(frs<req)localQ+=req-frs;
        }
        if(localQ<=cntq){
            lo=mid;
        }else hi=mid;
    }
    string sr="";
    for(auto x:b){
        int ansf=0;
        int ch=x.first,fr=x.second;
        int frs=a[ch];
        int req=fr*lo;
        if(frs<req)ansf+=req-frs;
        while(ansf--){
            sr.push_back(ch);
        }
    }
    if(sr==""){
        cleanUp(s,n);
        cout<<s<<'\n';
        return 0;
    }
    int p=0;
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            s[i]=sr[p];
            p++;
            if(p>=(int)sr.length())break;
        }
    }
    cleanUp(s,n);
    cout<<s<<'\n';

    return 0;
}