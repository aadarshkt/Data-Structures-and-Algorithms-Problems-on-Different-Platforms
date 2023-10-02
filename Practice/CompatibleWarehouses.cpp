
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void solve(){

    int a,b;
    cin>>a>>b;
    int x=0,fl=0;
    int pos=30;
    for(int i=30;i>=0;i--){
        if((a&(1<<i))||(b&(1<<i))){
            pos=i;break;
        }
    }
    for(int i=pos;i>=0;i--){
        if((!(a&(1<<i)))&&(!(b&(1<<i)))){
            if(!(a&(1<<i))){
                x|=(1<<i);
            }
        }
        else{
            if(!((a&(1<<i))&&(b&(1<<i)))){
                if(!fl){
                    if(!(a&(1<<i))){
                        x|=(1<<i);
                    }
                    fl=1;
                }else{
                    if((a&(1<<i))){
                        x|=(1<<i);
                    }
                }
            }
        }
    }
    cout<<x<<'\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

