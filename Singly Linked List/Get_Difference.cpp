#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node (int val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head,Node* &tail,int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = tail->next;
}

int find_diff(Node* head){
    int min=head->val;
    int max = head->val;
    while(head!=NULL){
        if(min>head->val){
            min = head->val;
        }
        if(max<head->val){
            max = head->val;
        }
        head = head->next;
    }
    int diff = max-min;
    return diff;
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int node;
    while(true){
        cin>>node;
        if(node==-1) break;
        insert_at_tail(head,tail,node);
    }
    cout << find_diff(head);

    return 0;
}