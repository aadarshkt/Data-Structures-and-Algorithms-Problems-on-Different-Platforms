#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

struct Node{
    int a = 5;
    int b = 6;
    int c = 7;
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //use arrow to get members from struct when you have pointer to that struct.
    Node* newPointerToNodeStruct = new Node();
    cout<<newPointerToNodeStruct->a<<'\n';

    //use '.' to get memebers of struct when you have actual variable instance representing that struct.
    Node newObjectInstance = Node();
    cout<<newObjectInstance.a<<'\n';

    return 0;
}