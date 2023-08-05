#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int MOD=1e9+7;
struct mint{
int x = 0;
mint(int y = 0){x = y; if(x < 0 || x >= MOD) x = (x%MOD+MOD)%MOD;}
mint(const mint &ope) {x = ope.x;}
mint operator-(){return mint(-x);}
mint operator+(const mint &ope){return mint(x) += ope;}
mint operator-(const mint &ope){return mint(x) -= ope;}
mint operator*(const mint &ope){return mint(x) *= ope;}
mint operator/(const mint &ope){return mint(x) /= ope;}
mint& operator+=(const mint &ope){
x += ope.x;
if(x >= MOD) x -= MOD;
return *this;
}
mint& operator-=(const mint &ope){
x += MOD - ope.x;
if(x >= MOD) x -= MOD;
return *this;
}
mint& operator*=(const mint &ope){
x *= ope.x, x %= MOD;
return *this;
}
mint& operator/=(const mint &ope){
int n = MOD-2; mint mul = ope;
while(n){
if(n & 1) *this *= mul;
mul *= mul;
n >>= 1;
}
return *this;
}
mint inverse(){return mint(1) / *this;}
bool operator ==(const mint &ope){return x == ope.x;}
bool operator !=(const mint &ope){return x != ope.x;}
};
mint modpow(mint a, int n){
if(n == 0) return mint(1);
if(n % 2) return a * modpow(a, n-1);
else return modpow(a*a, n/2);
}
istream& operator >>(istream &is, mint &ope){
int t; is >> t, ope.x = t;
return is;
}
ostream& operator <<(ostream &os, mint &ope){return os << ope.x;}
ostream& operator <<(ostream &os, const mint &ope){return os << ope.x;}

const int mod=1e9+7;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        vector<vector<int>> dp((1<<6),vector<int>(n,0));
        dp[v[0]][0]=1;
        for(int i=1;i<n;i++){
            dp[v[i]][i]=1;
            for(int mask=0;mask<(1<<6);mask++){
                (dp[mask][i]+=dp[mask][i-1])%=mod;
                (dp[mask&v[i]][i]+=dp[mask][i-1])%=mod;
            }
        }
        int ans=0;
        for(int mask=0;mask<(1<<6);mask++){
            int set=0;
            for(int i=0;i<=5;i++){
                if(mask&(1<<i)){
                    set++;
                }
            }
            if(set==k){
                (ans+=dp[mask][n-1])%=mod;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}