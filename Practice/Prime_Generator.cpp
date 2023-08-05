#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

vector<int> pri;
void sieve(int n){
    pri.resize(n+1,1);
    pri[0]=0;
    pri[1]=0;
    for(int i=2;i<n+1;i++){
        if(pri[i]){
            int m=i;//m is multiplier.
            pri[i]=1;
            while(i*m<n+1){
                pri[i*m]=0;
                m++;
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    sieve((long long)1e9+2);
    vector<int> prime;
    for(int i=0;i<1e9+1;i++){
        if(pri[i])prime.push_back(i);
    }
    while(t--){
        int m,n;cin>>m>>n;
        auto it=lower_bound(begin(prime),end(prime),m);
        if(it!=end(prime)){
            for(auto itr=it;itr<end(prime);itr++){
                if(*itr>n)break;
                cout<<*itr<<'\n';
            }
        }
        cout<<"\n";
    }

    return 0;
}