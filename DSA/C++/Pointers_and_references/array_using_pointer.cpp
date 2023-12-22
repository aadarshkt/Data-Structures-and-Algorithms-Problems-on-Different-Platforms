#include <bits/stdc++.h>
using namespace std;


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //dynamic memory allocation.
    int *a = new int[5]; //get address to first element of array.

    for(int i=0;i<5;i++){
        a[i] = i+1;
    }

    //a is the variable that stores the address of first value of array.

    cout<<"first value is "<<*a<<'\n';
    cout<<"second value is "<<*(a + 1)<<'\n';

    for(int i=0;i<5;i++){
        cout<<a[i]<<' ';
    }


    return 0;
}