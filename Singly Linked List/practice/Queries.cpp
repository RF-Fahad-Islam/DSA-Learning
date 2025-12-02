#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = tail->next;
}

void insert_at_head(Node* &head,Node* &tail, int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

int len(Node* head){
    int i = 0;
    while (head!=NULL)
    {
        head = head->next;
        i++;
    }
    return i;
    

}

void delete_head(Node* &head,Node* &tail){
  Node* deleteNode = head;
    head = head->next;
    if(head == NULL){
        tail = NULL;
    }
    delete deleteNode;
}

void delete_pos(Node* &head,Node *&tail,int pos){
    
    if (len(head)-1<pos) return;
    if(pos==0){
    delete_head(head,tail);
    return;
    } 
    Node* tmp = head;
    for (;--pos; tmp = tmp->next);
    Node* deleteNode=tmp->next;
    tmp->next = deleteNode->next;
    if(tmp->next == NULL){
        tail = tmp;
    }
    delete deleteNode;

}

void print_ll(Node* head){
    while(head!=NULL){
        cout << head->val << " ";
        head= head->next;
    }
    cout<<endl;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    int q;
    cin>>q;
    while(q--){
        int x,val;
        cin>>x>>val;
        if(x==0) insert_at_head(head,tail,val);
        else if (x==1) insert_at_tail(head,tail,val);
        else delete_pos(head,tail,val);
        print_ll(head);
    }
    return 0;
}