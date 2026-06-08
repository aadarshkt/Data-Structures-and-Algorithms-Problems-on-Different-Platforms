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
        if(mp[hd].second>lvl){
            mp[hd]={root->data,lvl};
        }
    }else mp[hd]={root->data,lvl};
    dfs(root->left,hd-1,lvl+1);
    dfs(root->right,hd+1,lvl+1);
}

vector<int> topView(Node* root){
    if(root==NULL)return {};

    queue<pair<int,Node*>> q;
    q.push({0, root});

    map<int, Node*> mp;
    vector<int> ans;

    while(!q.empty()) {
        Node* curr = q.front().second;
        int hd = q.front().first;
        q.pop();

        if(!mp.count(hd))mp[hd] = curr;

        if(curr->left)q.push({hd-1, curr->left});
        if(curr->right)q.push({hd+1, curr->right});
    }

    for(auto it : mp){
        ans.push_back(it.second->data);
    }

    return ans;

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}