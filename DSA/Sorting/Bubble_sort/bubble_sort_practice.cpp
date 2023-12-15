#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void bubble_sort(vector<int> &a){
    int n = a.size();

    //int i = 0, represents putting 1st largest element to correct position
    //int i = 1, second largest
    //Thus n - 1 correctly positioned elements are required.


    for(int i=0;i<n-1;i++){
        int fl = 0;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                fl = 1;
            }
        }
        if(!fl)break;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    for(int &x:a)cin>>x;

    bubble_sort(a);

    for(int x:a)cout<<x<<' ';

    return 0;
}