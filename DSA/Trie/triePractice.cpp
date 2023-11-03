#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//create trie Node with array of pointers to new TrieNode and isEndOfWord
//If a letter is present make that pointer not null filled with address of new TrieNode
//If that letter is end of word, then next TrieNode will contain isEndOfWord = true;

struct TrieNode{
    //array of pointers to new TrieNodes
    TrieNode* child[26];
    //isEndOfWord flag also called sentinel value
    bool isEndOfWord;
    //constructor
    // using new Key word returns pointer to new TrieNode;
    //with new Keyword instanciates new object;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isEndOfWord = false;
    }
};

void insert(TrieNode* root, string key){
    if(root == NULL)return;
    //create tail node pointer to point to new TrieNodes at the end.
    TrieNode* pCrawl = root; //pointer that is crawling
    for(int i=0;i<(int)key.length();i++){
        //if a letter is present, pointer at that index should not be null and should contain the address of new TrieNode.
        //if it is null make new node.
        int index = key[i] - 'a';
        if(!pCrawl->child[index]){
            pCrawl->child[index] = new TrieNode();
        }
        pCrawl = pCrawl->child[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(TrieNode* root, string key){
    if(root == NULL)return false;
    int n=key.length();
    TrieNode* pCrawl = root;
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

    vector<string> query = {"the", "therire", "byee", "thei"};

    for(int i=0;i<(int)query.size();i++){
        cout<<search(root,query[i])<<'\n';
    }

    

    return 0;
}