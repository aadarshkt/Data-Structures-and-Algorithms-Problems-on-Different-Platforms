#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool check(int x,int k){
    vector<int> po;
    int exp=3;
    po.push_back(exp);
    for(int i=0;i<39;i++){
        exp*=3;
        po.push_back(exp);
    }
    for(auto ele:po){
        if(x<=(ele-1)*k&&x%(ele-1)==0){
            return 1;
        }
    }
    return 0;
}

const int mod=1e9+7;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(57885954-352586971)+mod<<'\n';

    return 0;
}