#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node (int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_forward(Node* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}
void print_backward(Node* tail){
    while(tail){
        cout << tail->val << " ";
        tail = tail->prev;
    }
}

void insert_at_head(Node* &head,Node* &tail, int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insert_at_tail(Node* &head,Node* &tail, int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insert_any(Node* &head,Node* &tail, int val,int pos){
    if(pos==0){
        insert_at_head(head,tail,val);
        return;
    }
    Node* newnode = new Node(val);
    Node* tmp = head;
    for (int i = 0; i < pos-1; i++)
    {
        if(tmp==NULL) return;
        tmp = tmp->next;
    }
    newnode->next= tmp->next;
    tmp->next->prev = newnode;
    tmp->next = newnode;
    newnode->prev = tmp;
}

void delete_head(Node* &head,Node* &tail){
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
    if(head==NULL){
        tail=NULL;
        return;
    }
    head->prev = NULL;
}

void delete_tail(Node* &head, Node* &tail){
    Node* deleteNode= tail;
    tail = tail->prev;
    delete deleteNode;
    if(tail==NULL){
        head=NULL;
        return;
    }
    tail->next = NULL;
}

void delete_any(Node* &head, Node* &tail, int pos){
    if(pos==0){
        delete_head(head,tail);
        return;
    }
    Node* tmp = head;
    for (int i = 0; i < pos-1; i++)
    {
        if(!tmp) return;
        tmp= tmp->next;
    }
    Node* deleteNode = tmp->next;
    tmp->next = deleteNode->next;
    deleteNode->next->prev = tmp;
    if(tmp->next==NULL){
        tail = tmp;
    }
    delete deleteNode;
    
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(3);
    Node* tail = new Node(1);
    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;
    insert_at_head(head,tail,40);
    insert_at_tail(head,tail,30);
    insert_any(head,tail,500,2);
    delete_head(head,tail);
    delete_tail(head,tail);
    delete_any(head,tail,2);
    delete_tail(head,tail);
    delete_tail(head,tail);
    delete_any(head,tail,0);
    print_forward(head);
    return 0;   
}