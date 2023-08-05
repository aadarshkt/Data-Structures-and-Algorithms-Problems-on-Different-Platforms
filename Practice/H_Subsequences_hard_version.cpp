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

    int n,k;cin>>n>>k;
    k--;
    string s;cin>>s;
	vector<vector<int>> lst(n,vector<int>(26,-1));
	for(int i=0;i<n;i++){
		for (int j=0;j<26;j++){
			if(i>0)lst[i][j]=lst[i-1][j];
		}
		lst[i][s[i]-'a']=i;
	}
	vector<vector<int>> dp(n+1,vector<int>(n+1));
	for (int i=0;i<n;i++){
		dp[i][1]=1;
	}
	for(int len=2;len<n;len++){
		for(int i=1;i<n;i++){
			for(int j=0;j<26;j++){
				if(lst[i-1][j]==-1)continue;
				dp[i][len]=min((long long)1e12,dp[i][len]+dp[lst[i-1][j]][len-1]);
			}
		}
	}
	int ans=0;
	for(int len=n-1;len>=1;len--){
		int cnt=0;
		for(int j=0;j<26;j++){ 
			if(lst[n-1][j]==-1)continue;
			cnt+=dp[lst[n-1][j]][len];
		}
		if(cnt>=k){
			ans+=k*(n-len);
			k=0;
			break;
		}else{
			ans+=cnt*(n-len);
			k-=cnt;
		}
	}
	if(k==1){
		ans+=n;
		k--;
	}
	if(k>0)cout<<-1<<endl;
	else cout<<ans<<endl;

    return 0;
}