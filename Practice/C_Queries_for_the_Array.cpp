#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//if decreasing length is greater no problem
//if increasing length in smaller no problem
//idea is that the decreasing length requires only one element but increasing length requires all elements.
//mxL maximum increasing length dxL decreasing length.
//when adding do not change dxL or mxL
//when decreasing numbers update mxL always but dxL only one time.(first minus set dxL=inf)
//inital mxL -- 1 and dxL inf
//dxL update -- when zero query and mxL is lesser than count, dxL=count, mxL=count-1 else break No
//mxL update -- when dxL is greater and one query comes update mxL and dxL=inf else break No



int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string s;cin>>s;
        int n=s.length();
        int dxL=INT_MAX,mxL=1,cnt=0;
        int fl=1,fl2=0;//flag to check for first minus after 0 query, fl2=1 means 0 has come
        for(int i=0;i<n;i++){
            if(s[i]=='+'){
                cnt++;
            }
            else if(s[i]=='-'){
                cnt--;
                if(cnt<mxL)mxL=max(cnt,(int)1);
                if(cnt<dxL&&fl2){
                    fl2=0;
                    dxL=INT_MAX;
                }
            }
            else if(s[i]=='1'){
                if(dxL<=cnt){
                    fl=0;break;
                }else{
                    mxL=max(cnt,(int)1),dxL=INT_MAX;
                }
            }else{
                if(mxL>=cnt&&!(dxL<=cnt)){
                    fl=0;break;
                }else{
                    fl2=1;
                    mxL=max(cnt-1,(int)1),dxL=cnt;
                }
            }
        }
        if(fl)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}