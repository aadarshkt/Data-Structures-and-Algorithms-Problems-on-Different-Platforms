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

void add(deque<int> &q,int x){
    while(!q.empty()&&x>q.back()){
        q.pop_back();
    }
    q.push_back(x);
}

void remove(deque<int> &q,int x){
    if(q.front()==x)q.pop_front();
}

//for a given subarray length.
int fun(vector<int> &a,int n,int d){
    int ans=INT_MAX;
    int cnt=0;
    deque<int> q;
    for(int i=0;i<n;i++){
        add(q,a[i]);
        if(cnt<d)cnt++;
        if(cnt==d){
            remove(q,a[i-d]);
            ans=min(ans,q.front());
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;cin>>n>>q;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    for(int i=0;i<q;i++){
        int d;cin>>d;
        cout<<fun(a,n,d)<<'\n';
    }

    return 0;
}