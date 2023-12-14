#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long



//maintain horizontal and levels of all nodes
//in front view choose a horizontal distance will least lvl value
//in bottom view choose a hd will max lvl value.

struct Node{
    int data;
    Node *left,*right;
    Node(int x){
        data = x;
        left = NULL,right = NULL;
    }
};

map<int,pair<int,int>> mp;

void dfs(Node* root,int hd,int lvl){
    if(root==NULL)return;
    if(mp.count(hd)){
        if(mp[hd].second<lvl){
            mp[hd]={root->data,lvl};
        }
    }else mp[hd]={root->data,lvl};
    dfs(root->left,hd-1,lvl+1);
    dfs(root->right,hd+1,lvl+1);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}