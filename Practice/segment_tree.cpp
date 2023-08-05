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

    //segment tree
    int n;cin>>n;
    vector<int> arr(n);
    for(auto &x:arr)cin>>x;
    vector<int> tree(4*n);
    function<void(int,int,int)> build=[&](int node,int start,int end){
        if(start==end){
            tree[node]=arr[start];
        }else{
            int mid=(start+end)/2;
            build(2*node,start,mid);
            build(2*node+1,mid+1,end);
            tree[node]=tree[2*node]+tree[2*node+1];
        }
    };
    

    return 0;
}