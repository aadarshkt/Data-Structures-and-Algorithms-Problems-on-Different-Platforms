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
    vector<char> st;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(st.empty())st.push_back(s[i]);
        else{
            if(st.back()==s[i])st.pop_back();
            else st.push_back(s[i]);
        }
    }
    if(st.empty())cout<<"Empty String"<<'\n';
    else{
        for(char x:st)cout<<x;
        cout<<'\n';
    }

    return 0;
}