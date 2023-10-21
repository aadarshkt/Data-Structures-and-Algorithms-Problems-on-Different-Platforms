#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

#define ALPHABET_SIZE 26

//every trie node will contain 26 array of pointers to new trie nodes and isEndOfWord
//and a contructor to initialise values.

//each node has array of pointers, each pointer in array of pointers points 
// to another array of pointers. Basically means that for one letter you can have 26 possiblities for next letter.
//if a letter is possible, that position pointer array will not be NULL (see child initialisation)
//and will contain address of another array of pointers containing posibilites of next letter
struct TrieNode{
    TrieNode* child[ALPHABET_SIZE];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0;i<ALPHABET_SIZE;i++){
            child[i] = NULL;
        }
        isEndOfWord = false;
    }
};

void insert(TrieNode* root, string key){
    TrieNode* pCrawl = root;
    if(root == NULL)return;

    int n=key.length();

    for(int i=0;i<n;i++){
        int index = key[i] - 'a';
        if(!pCrawl->child[index]){
            pCrawl->child[index] = new TrieNode();
        }
        pCrawl=pCrawl->child[index];
    }
    pCrawl->isEndOfWord=true;
}

bool search(TrieNode* root, string key){
    if(root == NULL)return false;
    int n=key.length();
    TrieNode* pCrawl = root;
    //pCrawl is pointer to a struct
    //arrow is used to get members of struct from it pointer.
    for(int i=0;i<n;i++){
        int index = key[i] - 'a';
        if(!pCrawl->child[index]){
            return false;
        }
        pCrawl = pCrawl->child[index];
    }
    return pCrawl->isEndOfWord;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> dictionary = 
        {"the", "a", "there",
        "answer", "any", "by",
        "bye", "their"};

    TrieNode* root = new TrieNode();

    for(int i=0;i<(int)dictionary.size();i++){
        insert(root,dictionary[i]);
    }

    vector<string> query = {"the", "therire", "byee", "their"};

    for(int i=0;i<(int)query.size();i++){
        cout<<search(root,query[i])<<'\n';
    }
    

    return 0;
}