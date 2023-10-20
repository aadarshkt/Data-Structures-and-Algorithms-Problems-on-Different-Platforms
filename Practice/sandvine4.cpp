#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//find if s1 is present in s2;
bool isSubstring(string &s1,string &s2){
    if(s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1;cin>>s1;
    string s2;cin>>s2;

    int n1=s1.length(),n2=s2.length();
    s1=s1+s1;

    if(isSubstring(s2,s1))cout<<"Present"<<'\n';
    else cout<<"Not Present"<<'\n';

    return 0;
}