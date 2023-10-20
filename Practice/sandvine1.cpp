#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

struct Node{
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(20);

    Node* head2 = new Node(2);
    head2->next = new Node(10);
    head2->next->next = new Node(20);

    ListNode* l1 = head1;
    ListNode* l2 = head2;

    ListNode* ans = new ListNode(0);//dummy starting node.
    ListNode* tail = ans;

    while(l1!=NULL && l2!=NULL){
        if(l1->val >= l2->val){
            ListNode* newTailNode = new ListNode(l2->val);
            tail->next = newTailNode;
            tail=tail->next;
            l2=l2->next;
        }else if(l1->val < l2->val){
            ListNode* newTailNode = new ListNode(l1->val);
            tail->next = newTailNode;
            tail=tail->next;
            l1=l1->next;
        }
    }

    tail->next = l1 ? l1 : l2;
    return ans->next;

    return 0;
}