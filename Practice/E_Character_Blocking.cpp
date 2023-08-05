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

    int test;
    cin >> test;
    while(test--){
        string s1,s2;cin>>s1>>s2;
        int n=s1.length();
        int t,q;cin>>t>>q;
        vector<int> fl(n,0);
        int uneq=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                fl[i]=1;
                uneq++;
            }
        }
        queue<int> qu;
        int louneq=0;
        for(int i=0;i<q;i++){
            int ty;cin>>ty;
            if(!qu.empty()){
                int fr=qu.front();
                if(fr==i){
                    qu.pop();
                    louneq--;
                }
            }
            if(ty==3){
                if(uneq==louneq)cout<<"YES"<<'\n';
                else cout<<"NO"<<'\n';
            }else if(ty==1){
                int pos;cin>>pos;
                pos--;
                if(fl[pos]){
                    qu.push(i+t);
                    louneq++;
                }
            }else{
                int nos1,pos1,nos2,pos2;cin>>nos1>>pos1>>nos2>>pos2;
                pos1--,pos2--;
                char c1,c2;
                if(nos1==1)c1=s1[pos1];
                else c1=s2[pos1];
                if(nos2==1){
                    c2=s1[pos2];
                    s1[pos2]=c1;
                }
                else{
                    c2=s2[pos2];
                    s2[pos2]=c1;
                }
                if(nos1==1){
                    s1[pos1]=c2;
                }else{
                    s2[pos1]=c2;
                }
                dbg(s1,s2);
                if(fl[pos1]&&s1[pos1]==s2[pos1]){
                    uneq--;
                    fl[pos1]=0;
                }else if(!fl[pos1]&&s1[pos1]!=s2[pos1]){
                    fl[pos1]=1;
                    uneq++;
                }
                if(fl[pos2]&&s1[pos2]==s2[pos2]){
                    uneq--;
                    fl[pos2]=0;
                }else if(!fl[pos2]&&s1[pos2]!=s2[pos2]){
                    fl[pos2]=1;
                    uneq++;
                }
            }
        }
    }

    return 0;
}