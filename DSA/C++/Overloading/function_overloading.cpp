#include <bits/stdc++.h>
using namespace std;


int sum(int a,int b){
    return a + b;
}

double sum(double a, double b){
    return a + b;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<sum(5, 6)<<'\n';
    cout<<sum(3.14, 4.667)<<'\n';

    return 0;
}