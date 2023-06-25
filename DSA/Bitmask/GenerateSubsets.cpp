#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void display(int mask){
    //64 causes problems.
    for(int i=0;i<32;i++){
        if(mask&(1<<i))cout<<i+1<<' ';
    }
    cout<<'\n';
}

void printSub(int mask, int maskLen){
    if(mask==0)return;
    display(mask);
    for(int i=0;i<maskLen;i++){
        if(mask&(1<<i)){
            printSub(mask^(1<<i),maskLen);
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //generate subsets of natural numbers upto 7; s = {1, 2, 3, 4, 5, 6, 7};
    printSub((1<<3)-1,3);

    return 0;
}