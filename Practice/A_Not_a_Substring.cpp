#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void fun(string &s,int n){
    for(int i=0;i<n;i++){
        if(s[i]=='('&&s[i+1]==')'){
            s[i]=')';
            s[i+1]='(';
            break;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string s;cin>>s;
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.empty())st.push(s[i]);
            else{
                if(st.top()=='('&&s[i]==')'){
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        if(st.empty()){
            if(n<4)cout<<"NO"<<'\n';
            else{
                fun(s,n);
                cout<<s+s<<'\n';
            }
        }else{
            deque<int> dq;
            for(int i=0;i<n;i++){
                dq.push_back(s[i]);
            }
            for(int i=0;i<n;i++){
                if(s[i]=='()')
            }
        }
    }

    return 0;
}