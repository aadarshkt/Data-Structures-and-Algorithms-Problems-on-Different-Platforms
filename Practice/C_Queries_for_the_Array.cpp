int solve(string num,int i,int n,int t,int fl,int prev){
        if(i==n)return 1;
        int ans=0;
        if(fl==0){
            for(int j=0;j<=9;j++){
                int newFl=j==0?0:1;
                (ans+=solve(num,i+1,n,0,newFl,j))%=mod;
            }
        }else{
            if(t==1){
                int curr=num[i]-'0';
                if(prev==0){
                    if(prev+1<curr){
                        (ans+=solve(num,i+1,n,0,1,prev+1))%=mod;
                    }else if(prev+1==curr){
                        (ans+=solve(num,i+1,n,1,1,prev+1))%=mod;
                    }
                }else if(prev==9){
                    if(prev-1<curr&&prev>=1){
                       (ans+=solve(num,i+1,n,0,1,prev-1))%=mod;
                    }else if(prev-1==curr){
                        (ans+=solve(num,i+1,n,1,1,prev-1))%=mod;
                    }
                }else{
                    if(prev+1<curr){
                        (ans+=solve(num,i+1,n,0,1,prev+1))%=mod;
                    }else if(prev+1==curr){
                        (ans+=solve(num,i+1,n,1,1,prev+1))%=mod;
                    }
                    if(prev-1<curr&&prev>=1){
                        (ans+=solve(num,i+1,n,0,1,prev-1))%=mod;
                    }else if(prev-1==curr){
                        (ans+=solve(num,i+1,n,1,1,prev-1))%=mod;
                    }
                }
            }else{
                if(prev==0){
                    ans+=solve(num,i+1,n,0,1,prev+1);
                }else if(prev==9){
                    ans+=solve(num,i+1,n,0,1,prev-1);
                }else{
                    if(prev+1<=9)(ans+=solve(num,i+1,n,0,1,prev+1))%=mod;
                    if(prev-1>=0)(ans+=solve(num,i+1,n,0,1,prev-1))%=mod;
                }
            }
        }
        return ans;
        
    }