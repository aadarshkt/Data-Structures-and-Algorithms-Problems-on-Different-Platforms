#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

struct TrieNode{
    TrieNode* child[26];
    int count;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        count = 0;
    }
};

void insert(TrieNode* root, string key){
    if(root == NULL)return;
    TrieNode* pCrawl = root;
    for(int i=0;i<(int)key.length();i++){
        int index = key[i] - 'a';
        if(!pCrawl->child[index]){
            pCrawl->child[index] = new TrieNode();
        }
        pCrawl = pCrawl->child[index];
        pCrawl->count++;
    }
}

TrieNode* findPointerToNextTrie(TrieNode* root, string key){
    if(root == NULL)return NULL;
    int n=key.length();
    TrieNode* pCrawl = root;
    for(int i=0;i<n;i++){
        int index = key[i] - 'a';
        if(!pCrawl->child[index]){
            return NULL;
        }
        pCrawl = pCrawl->child[index];
    }
    return pCrawl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;cin>>n>>q;
    TrieNode* root = new TrieNode();
    for(int i=0;i<n;i++){
        string s;cin>>s;
        insert(root, s);
    }
    for(int i=0;i<q;i++){
        string s;cin>>s;
        TrieNode* nextPointer = findPointerToNextTrie(root,s);
        if(nextPointer==NULL){
            cout<<0<<'\n';continue;
        }
        cout<<nextPointer->count<<'\n';
    }

    return 0;
}