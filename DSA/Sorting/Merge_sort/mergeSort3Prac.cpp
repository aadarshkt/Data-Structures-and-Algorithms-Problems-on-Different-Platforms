#include <bits/stdc++.h>
using namespace std;

//merge --> merge in O(N)
//mergeSort --> divide O(Logn)

//merge values of two subarrays
void merge(vector<int> &arr,int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    vector<int> left(n1),right(n2);
    int k=l,i=0,j=0;

    for(int p=l;p<=m;p++){
        left[p-l]=arr[p];
    }
    for(int p=m+1;p<=r;p++){
        right[p-m-1]=arr[p];
    }
    while(k<=r){
        if(left[i]<=right[i]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
}

void mergeSort(vector<int> &arr,int l,int r){
    int m = l + (r - l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {5,4,3,2,1};
    mergeSort(arr,0,4);
    for(int x:arr)cout<<x<<' ';

    

    return 0;
}