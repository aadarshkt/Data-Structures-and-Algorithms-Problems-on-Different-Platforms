#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void bubble_sort(vector<int> &a,int n){
    if(n==1)return;

    int fl = 0;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
            fl = 1;
        }
    }

    if(!fl)return;

    bubble_sort(a,n-1);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    for(int &x:a)cin>>x;

    bubble_sort(a,n);

    for(int x:a)cout<<x<<' ';

    return 0;
}