#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//l to mid and mid + 1 to r is sorted
void merge(vector<int> &a,int l,int mid,int r,int &count){
    int n1 = mid-l+1, n2 = r-mid;
    vector<int> left(n1),right(n2);
    for(int i=l;i<=mid;i++){
        left[i-l] = a[i];
    }
    for(int i=mid+1;i<=r;i++){
        right[i-mid-1] = a[i];
    }
    int i = 0, j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(left[i] > right[j]){
            count += n1 - i;
            a[k] = right[j];
            j++;k++;
        }else{
            a[k] = left[i];
            i++,k++;
        }
    }
    while(i < n1){
        a[k] = left[i];
        i++;k++;
    }
    while(j < n2){
        a[k] = right[j];
        j++;k++;
    }
}

void merge_sort(vector<int> &a,int l,int r,int &count){
    if(l>=r)return;
    int mid = l + (r - l)/2;
    merge_sort(a,l,mid,count);
    merge_sort(a,mid+1,r,count);
    merge(a,l,mid,r,count);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> arr(n);
    for(int &x:arr)cin>>x;
    int count = 0;
    merge_sort(arr,0,n-1,count);
    cout<<count<<'\n';
    for(int x:arr)cout<<x<<' ';


    return 0;
}