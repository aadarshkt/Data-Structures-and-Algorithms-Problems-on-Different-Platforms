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

    string s;cin>>s;
    int n=s.length();
    int fl=0,fl5=0;
    string s1="";
    string ans1="",ans2="";
    for(int i=0;i<n;i++){
        if(s[i]==','||s[i]==';'){
            dbg(s1);

            dbg(fl,fl5);
            if(s1[0]=='0'&&s1.length()>1)fl5=1;
            if(fl||s1==""||fl5){
                ans2+=(s1);
                dbg(ans2);
                ans2.push_back(',');
            }else{
                ans1+=s1;
                ans1.push_back(',');
                dbg(ans1,s1);
            }
            fl5=0,fl=0;
            s1="";
        }else{
            s1+=s[i];
            if(!(s[i]-'0'>=0&&s[i]-'0'<=9))fl=1;
        }
    }
    if(((s[n-1]!=',')||(s[n-1]!=';'))&&(s1.length()>0)){
        if(s1[0]=='0'&&s1.length()>1)fl5=1;
        if(fl||s1==""||fl5){
            ans2+=(s1);
            dbg(ans2);
            ans2.push_back(',');
        }else{
            ans1+=s1;
            ans1.push_back(',');
            dbg(ans1,s1);
        }
    }
    if(ans1.length()>0)ans1.pop_back();
    if(ans2.length()>0&&(s[n-1]!=','&&s[n-1]!=';'))ans2.pop_back();

    if(ans1.length()==0)cout<<"-"<<'\n';
    else cout<<"\""<<ans1<<"\""<<'\n';
    if(ans2.length()==0&&(s[n-1]!=','&&s[n-1]!=';'&&s[0]!=','&&s[0]!=';'))cout<<"-"<<'\n';
    else cout<<"\""<<ans2<<"\""<<'\n';

    return 0;
}