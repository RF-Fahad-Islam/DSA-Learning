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

bool is_same_len(Node* head1, Node* head2){
    int i=0,j=0;
    while(head1 != NULL) {head1 = head1->next;i++;}
    while(head2 != NULL) {head2 = head2->next;j++;}
    if(i!=j) return false;
    else true;

}
void print_ll(Node* head){
    while(head!=NULL){
        printf("%d -> ", head->val);
        head = head->next;
    }
}

int find_max(Node *head){
    int max = head->val;
    head = head->next;
    while(head != NULL){
        if(max<head->val) max = head->val;
        head = head->next;
    }
    return max;
}

void des(Node* head){
    while(head!=NULL){
        Node* next2 = head->next;
        while(next2!=NULL){
            if(head->val<next2->val){
                int tmp = head->val;
                head->val = next2->val;
                next2->val = tmp;
            }
            next2= next2->next;
        }
        head = head->next;
    }
}

int main(){
    int node;
    cin>>node;
    Node* head = new Node(node);
    Node* curr = head;
    while(true){
        cin>>node;
        if (node==-1) break;
        Node* newnode = new Node(node);
        curr->next = newnode;
        curr = curr->next;
    }
    cin>>node;
    Node* head2 = new Node(node);
    curr = head2;
    while(true){
        cin>>node;
        if (node==-1) break;
        Node* newnode = new Node(node);
        curr->next = newnode;
        curr = curr->next;
    }
    if(is_same_len(head,head2)) printf("SAME");
    else printf("NOT SAME");
    printf("%d",find_max(head));
    des(head);
    print_ll(head);
    return 0;
}