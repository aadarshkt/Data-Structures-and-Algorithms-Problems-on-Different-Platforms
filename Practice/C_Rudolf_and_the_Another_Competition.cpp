#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool sortbyCond(const pair<int, pair<int,int>>& a,
                const pair<int, pair<int,int>>& b)
{
    if (a.second.first != b.second.first)
        return (a.second.first < b.second.first);
    else
       return (a.second.second > b.second.second);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,m,h;cin>>n>>m>>h;
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        for(int i=0;i<n;i++){
            sort(begin(v[i]),end(v[i]));
        }
        vector<pair<int,pair<int,int>>> ans;
        for(int i=0;i<n;i++){
            int check=0;
            int p=0;
            for(int j=0;j<m;j++){
                check+=v[i][j];
                p+=check;
                if(check>h){
                    ans.push_back({i,{j,p-check}});
                    break;
                }else if(check==h){
                    ans.push_back({i,{j+1,p}});
                    break;
                }
            }
            if(check<h)ans.push_back({i,{m,p}});
        }
        dbg(v);
        sort(begin(ans),end(ans),sortbyCond);
        reverse(begin(ans),end(ans));
        dbg(ans);
        int sz=ans.size();
        int sc=0,p=0;
        for(int i=0;i<sz;i++){
            if(ans[i].first==0){
                sc=ans[i].second.first;
                p=ans[i].second.second;
            }
        }
        for(int i=0;i<sz;i++){
            int scx=ans[i].second.first,px=ans[i].second.second;
            if(scx==sc&&px==p){
                cout<<i+1<<'\n';
                break;
            }
        }

    }

    return 0;
}