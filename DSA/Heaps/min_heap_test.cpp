#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int,vector<int>,greater<int>> pq;

    pq.push(10);
    pq.push(8);
    pq.push(7);

    cout<<"TOP is "<<pq.top()<<'\n';

    pq.push(1);

    pq.pop();

    cout<<"TOP is "<<pq.top()<<'\n';

    return 0;
}