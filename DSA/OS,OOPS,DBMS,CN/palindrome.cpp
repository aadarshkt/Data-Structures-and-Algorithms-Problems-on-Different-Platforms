#include<bits/stdc++.h> 
using namespace std;

#define all(x) begin(x), end(x)
#define int long long

vector<int> palin;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> pref(n+1);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    for (int i=0;i<n;i++){ 
        pref[i+1]-pref[i]+a[i];
    }
    auto get=[&](int l,int r){ 
        if(r<l) return 0ll;
        return pref[r+1]-pref[1];
    };
    int ans=1e18;
    for(auto x:palin){
        auto it=lower_bound(all(a),x)-begin(a);
        int res = it*x-get(0,it-1)-x*(n-it)+get(it,n-1);
        ans=min(ans,res);
    }
    cout<<ans<<'\n';
}

int createPalindrome(int input,int b,bool isOdd){
    int n=input;
    int pal=input;
    if(isOdd) n/=b;
    while(n>0){
        pal=pal*b+(n%b);
        n/=b;
    }
    return pal;
}

void generate(int n){
    int number;
    for(int j=0;j<2;j++){
        int i=1;
        while((number=createPalindrome(i,10,j%2))<n){
            palin.push_back(number);
            i++;
        }
    }
}

int32_t main(){
    int nn=1e12;
    generate(nn);
    int t;cin>>t;
    while(t--){
        solve();
    }
}