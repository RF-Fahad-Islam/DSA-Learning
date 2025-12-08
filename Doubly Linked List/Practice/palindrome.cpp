#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node (int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    return;

}

bool is_palindrome(Node* head,Node* tail){
    for (Node *i = head, *j = tail; j != i && i->prev != j; i = i->next, j = j->prev)
    {
        if(i->val != j->val)  return false;
    }
    return true;
    
}

int main()
{
    int v;
    Node* head = NULL;
    Node* tail = NULL;
    while(cin>>v && v != -1){
        insert_at_tail(head,tail,v);
    }
    if(is_palindrome(head,tail)) cout << "YES";
    else cout << "NO";
    return 0;
}
