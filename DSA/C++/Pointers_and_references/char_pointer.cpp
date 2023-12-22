#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char* c = "Hello";

    

    char d[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    

    cout<<"d is "<<d<<'\n';
    cout<<"c is "<<c<<'\n';
    cout<<static_cast<void*>(c+1)<<'\n';
    cout<<*(c+1)<<'\n';

    //array pointer

    int a[] = {5, 10, 15};
    int* e = a;

    cout<<*(e+1)<<'\n';

    

    return 0;
}