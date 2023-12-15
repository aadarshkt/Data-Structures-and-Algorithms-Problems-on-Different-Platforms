#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//main idea - start from pos 1 and keep positioning the element at right position in the sorted part.

//start from left and for every new element find it's correct position in the sorted list and INSERT it.

void selection_sort(vector<int> &a){
    int n = a.size();

    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
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

    selection_sort(a);

    for(int x:a)cout<<x<<' ';
    
    return 0;
}