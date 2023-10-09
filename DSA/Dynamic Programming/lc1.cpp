class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n=s1.length();
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i])cnt++;
        }
        if(cnt%2!=0)return -1;
        int p1=0,p2=p1+1;
        while(p1<n&&p2<n){
            if(s1[p1]!=s2[p1]){
                while(p2<n){
                    if(s1[p2]!=s2[p2]){
                        
                        ans+=min(x,p2-p1);
                        p1=p2+1;
                        p2=p1+1;
                        break;
                    }else p2++;
                }
            }else p1++;
        }
        return ans;
    }
};