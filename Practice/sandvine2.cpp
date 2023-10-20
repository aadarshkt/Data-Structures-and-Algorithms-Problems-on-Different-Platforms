#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool isValid(string s) {
    int n=s.length();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(st.empty())st.push(s[i]);
        else{
            if(st.top()=='('&&s[i]==')')st.pop();
            else if(st.top()=='{'&&s[i]=='}')st.pop();
            else if(st.top()=='['&&s[i]==']')st.pop();
            else{
                st.push(s[i]);
            }
        }
    }
    if(st.empty())return true;
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}