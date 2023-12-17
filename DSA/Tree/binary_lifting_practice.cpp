#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//basic idea -> Jump from any node can be decomposed into powers of 2.
//for eg -> you want to jump x units from node y.
//then x can be expressed as sum of powers of 2.(binary representation)
//Now, to find it, you need to know where you will reach after jumping every power of 2 from particular node.
//In short find every power of 2 jump from every node.
//So if you want to jump to x units from node y, then lets say x binary representation is 1 1 1 0
//then if you know for every node every power of 2 jump destination
//then to jump from x
//you need to jump 2^(1) then from there 2^(2) then from there 2^(3), then your destination is reached in cei(log(x)) time.

//dynamic programming comes when to calculate a higher power of 2 you need to jump 2 time lower power of 2.

//dp[i][j] --> you need to caculate where you will reach by jumping from node i a jump of 2^(j);
//to calculate it just jump two 2^(j-1), like 4 + 4 = 8;
//thus dp[i][j] = dp[dp[i][j-1]][j-1];
//lower powers of 2 need to be calculated first.

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}