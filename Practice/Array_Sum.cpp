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
        int n,k;cin>>n>>k;
        if((n/2)%2==0){
            if(k%2!=0)cout<<-1<<'\n';
            else{
                int q=k/n;
                dbg(t,q);
                if(q>=(int)1e5||(q<=1))cout<<-1<<'\n';
                else{
                    vector<int> ans;
                    for(int i=0;i<n;i++)ans.push_back(q);
                    for(int i=0;i<n/2;i+=2){
                        ans[i]-=1;ans[i+1]+=1;
                    }
                    dbg(ans);
                    int fl=1;
                    for(int i=0;i<n;i++){
                        if((ans[i]<1)||(ans[i]>(int)1e5)){fl=0;break;}
                    }
                    if(!fl)cout<<-1<<'\n';
                    else{
                        for(int i:ans)cout<<i<<' ';
                        cout<<'\n';
                    }
                }
            }
        }else{
            if(k%2==0)cout<<-1<<'\n';
            else{
                double q=(double)k/n;
                if(q>=(double)1e5||(q<=1))cout<<-1<<'\n';
                else{
                    vector<int> ans;
                    for(int i=0;i<n;i++){
                        if(i%2==0)ans.push_back(floor(q));
                        else ans.push_back(ceil(q));
                    }
                    int fl=1;
                    for(int i=0;i<n;i++){
                        if((ans[i]<1)||(ans[i]>(int)1e5)){fl=0;break;}
                    }
                    if(!fl)cout<<-1<<'\n';
                    else{
                        for(int i:ans)cout<<i<<' ';
                        cout<<'\n';
                    }
                }
            }
        }
    }

    return 0;
}