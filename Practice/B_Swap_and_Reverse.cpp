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

    int t;
    cin >> t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        if(k%2==0){
            sort(begin(s),end(s));
            cout<<s<<'\n';
        }else{
            string a,b;
            for(int i=0;i<n;i++){
                if(i%2==0)a.push_back(s[i]);
                else b.push_back(s[i]);
            }
            sort(begin(a),end(a));
            sort(begin(b),end(b));
            int p1=0,p2=0;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    s[i]=a[p1];p1++;
                }else{
                    s[i]=b[p2];p2++;
                }
            }
            cout<<s<<'\n';
        }
    }

    return 0;
}