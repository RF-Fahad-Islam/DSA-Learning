#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }

};

void sort_ll(Node* &head){
    Node* cur= head;
    while (cur != NULL){
        Node* cur_next = cur->next;
        while(cur_next != NULL){
            if(cur->val > cur_next->val){
                int temp = cur_next->val;
                cur_next->val = cur->val;
                cur->val = temp;
            }
            cur_next= cur_next->next;
        }
        cur = cur->next;
    }
}

void print_ll(Node* head){
    while(head!=NULL){
        printf("%d -> ", head->val);
        head = head->next;
    }
}

int main(){
    Node* head = new Node(2);
    Node* a = new Node(3);
    Node* b = new Node(1);
    head->next =a;
    a->next = b; 
    sort_ll(head);
    print_ll(head);
    return 0;
}