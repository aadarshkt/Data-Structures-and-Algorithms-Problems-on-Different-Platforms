#include <bits/stdc++.h>
using namespace std;

class vertex {
public :
    int a[7];
    int temp[7];
    void help() {
        for(int i = 0; i < 7; i++){
            a[i] = temp[i];
        }
    }
    void adjustCost(int n[7], int m) {
        for (int i = 0; i < 7; i++) {
            if (n[i] != 100 && (temp[i] == 100 || temp[i] > n[i] + temp[m])) {
                temp[i] = n[i] + temp[m]; 
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    
    vector<vector<int>> grid(7, vector<int>(7));
    // to store neighbours
    vector<int> adj[7]; 
    
    for(int i = 0; i < 7; i++){
        for(int j = i; j < 7; j++){
            cout<<"Enter cost (max:100) of the node "<<j<<" from "<<i<<endl;
            int x;
            cin >> x;
            grid[i][j] = x;
            grid[j][i] = x;
            if(i != j && x != 100){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    vertex routers[7];
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            routers[i].a[j] = grid[i][j];
            routers[i].temp[j] = grid[i][j];
        }
    }

    for(int k = 0; k < 7; k++) {
        for(int i = 0; i < 7; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                routers[i].adjustCost(routers[adj[i][j]].a, adj[i][j]);
            }
        }
        for(int i = 0; i < 7; i++){
            routers[i].help();
        }
    }
    cout << '\n';
    cout << "The Input Cost Matrix"<<'\n';
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "The Updated Matrix after 7 iterations" << endl;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            cout << routers[i].a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}