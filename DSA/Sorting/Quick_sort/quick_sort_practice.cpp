#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int correct_pos(vector<int> &a,int lo,int hi){
    //choose any pivot
    int pivot = a[lo];
    int i = lo;
    //keep swapping lower values to i and increase i
    for(int j=lo;j<=hi;j++){
        if(a[j]<pivot){
            swap(a[i],a[j]);
            i++;
        }
    }
    //pivot is bound to remain at i or greater than i,
    //all elements greater than pivot are there at greater than or equal to i.
    swap(a[i],pivot);
    return i;
}

void quick_sort(vector<int> &a,int lo,int hi){
    if(lo>=hi)return;
    int p = correct_pos(a,lo,hi);
    quick_sort(a,lo,p-1);
    quick_sort(a,p,hi);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int idx = (rand() % (50 - 10 + 1)) + 10;
    dbg(idx);

    int n;cin>>n;
    vector<int> a(n);
    for(int &x:a)cin>>x;

    quick_sort(a,0,n-1);

    for(int x:a)cout<<x<<' ';


    return 0;
}