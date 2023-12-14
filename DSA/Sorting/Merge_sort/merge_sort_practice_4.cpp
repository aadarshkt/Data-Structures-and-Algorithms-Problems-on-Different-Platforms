#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//sorted from lo to mid and mid+1 to hi
void merge(vector<int> &a,int lo,int mid,int hi){
    int n1 = mid-lo+1, n2 = hi - mid;
    vector<int> left(n1),right(n2);
    for(int i=lo;i<=mid;i++){
        left[i-lo] = a[i];
    }
    for(int i=mid+1;i<=hi;i++){
        right[i-mid-1] = a[i];
    }
    int p1 = 0, p2 = 0, p3 = lo;
    while(p1<n1&&p2<n2){
        if(left[p1]<right[p2]){
            a[p3] = left[p1];
            p1++;
            p3++;
        }else{
            a[p3] = right[p2];
            p2++;
            p3++;
        }
    }
    while(p1<n1){
        a[p3] = left[p1];
        p3++;p1++;
    }
    while(p2<n2){
        a[p3] = right[p2];
        p3++;
        p2++;
    }
}


void merge_sort(vector<int> &a,int lo,int hi){
    if(lo>=hi)return;
    int mid = lo + (hi - lo) / 2;
    merge_sort(a,lo,mid);
    merge_sort(a,mid+1,hi);
    merge(a,lo,mid,hi);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    for(int &x:a)cin>>x;

    merge_sort(a,0,n-1);

    for(int x:a)cout<<x<<' ';

    return 0;
}