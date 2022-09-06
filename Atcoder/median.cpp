#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 3;
    int arr[3];

    for(int i=0; i<3; i++) cin>>arr[i];

    int b = arr[1];

    sort(arr, arr + 3);

    if(b == arr[1]) 
    {
        cout << "Yes" << endl;
    }
    else 
    {
        cout << "No" << endl;
    }





    return 0;
}