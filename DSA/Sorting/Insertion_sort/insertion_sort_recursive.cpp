#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void insertion_sort(vector<int> &a,int n){
    if(n<=1)return;

    insertion_sort(a,n-1);

    for(int j=n-1;j>0;j--){
        if(a[j]<a[j-1]){
            swap(a[j],a[j-1]);
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    for(int &x:a)cin>>x;

    insertion_sort(a,n);

    for(int x:a)cout<<x<<' ';


    return 0;
}