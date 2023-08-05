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
        int n;cin>>n;
        string s;cin>>s;
        if(n%2!=0){
            cout<<-1<<'\n';
            continue;
        }
        map<char,int> mp;
        int cor=0;
        for(int i=0;i<(n/2);i++){
            if(s[i]==s[n-i-1])mp[s[i]]++;
            else cor++;
        }
        vector<int> f;
        for(auto x:mp){
            f.push_back(x.second);
        }
        int sz=f.size();
        if(sz==1){
            if(cor>=f[0]){
                cout<<f[0]<<'\n';
            }else cout<<-1<<'\n';
            continue;
        }
        if(sz==0)cout<<0<<"\n";
        else{
            sort(rbegin(f),rend(f));
            int p=0;//current greatest.
            dbg(t,mp,f);    
            int i=1;
            int ans=0;
            while(i<sz&&p<sz){
                if(f[p]<f[i]){
                    swap(p,i);
                }
                f[p]-=f[i];
                f[i]=0;
                if(f[p]==0){p+=2,i+=2;}
                else i++;
                ans+=f[i];
            }
            dbg(p,f,cor);
            if(p<sz&&f[p]>0){
                if(f[p]<=cor){
                    ans+=f[p];
                }else{
                    cout<<-1<<'\n';
                    continue;
                }
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}