#include <bits/stdc++.h>
using namespace std;

struct vertex {
    int a[7];
    int temp[7];
    void help(){
        for(int i=0;i<7;i++){
            a[i]=temp[i];
        }
    }
    void adjustCost(int n[7],int m){
        for(int i=0;i<7;i++){
            if(temp[i] > n[i] + temp[m]){
                temp[i] = temp[m] + n[i];
            }
        }
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> cost(7,vector<int>(7)),adj(7);

    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cin>>cost[i][j];
            if(i!=j){
                adj[i].push_back(j);
            }
        }
    }

    vertex routers[7];
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            routers[i].a[j]=cost[i][j];
            routers[i].temp[j]=cost[i][j];
        }
    }

    for(int k=0;k<7;k++){
        for(int i=0;i<7;i++){
            for(int j=0;j<adj[j].size();j++){
                routers[i].adjustCost(routers[adj[i][j]].a,adj[i][j]);
            }
        }
        for(int i=0;i<7;i++){
            routers[i].help();
        }
    }

    cout<<"Input cost matrix "<<'\n';
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cout<<cost[i][j]<<' ';
        }
        cout<<'\n';
    }

    cout<<"Updated distance vector "<<'\n';
    for(int i=0;i<7;i++){
        cout<<"router "<<(i+1)<<" distance vector is ";
        for(int j=0;j<7;j++){
            cout<<routers[i].a[j]<<' ';
        }
        cout<<'\n';
    }


    return 0;
}