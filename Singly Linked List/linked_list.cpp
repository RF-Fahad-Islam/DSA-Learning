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

void print_list(Node* head){
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

void count(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    cout << cnt << endl;
}

void prepend(Node* &head,int val){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

// void append(Node* &head, int val){
//     Node* newnode = new Node(val);
//     if (head == NULL){
//         head = newnode;
//         return;
//     }
//     Node* temp = head;
//     while(temp->next != NULL){
//         temp = temp->next;
//     }
//     temp->next = newnode;
// }

void insert_tail(Node* &head, Node* &tail,int val){
    // Optimized append
    Node* newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void insert(Node* &head,Node* &tail,int val,int pos){
    Node* newnode = new Node(val);
    Node* temp = head;
    if (pos ==0 ){
        prepend(head,val);
    }
    for (int i = 1; i < pos; i++)
    {
        if(temp->next != NULL){
            temp = temp->next;
        } else break;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    if(newnode->next == NULL){
        tail = newnode;
    }
    
}

//Deletion
void delete_head(Node* &head){
    if(head==NULL) return;
    Node* next_node = head->next;
    delete head;
    head = next_node;
}

void delete_tail(Node* head){
    //Get prev node of tail
    Node* tmp = head;
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    //tail
    Node* deleteNode = tmp->next;
    tmp->next = NULL;
    delete deleteNode;
}

void delete_pos(Node* &head, int pos){
    if(pos == 0){
        delete_head(head);
        return;
    }
    Node* tmp = head;
    for (int i = 1; i < pos; i++)
    {
        if(tmp==NULL) return;
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;
    tmp->next = deleteNode->next;
    delete deleteNode;

}

void print_reverse(Node* head){
    Node* temp = head;
    if (temp == NULL) return;
    print_reverse(temp->next);
    cout << temp->val << " ";
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    // Node* a = new Node(2);
    // Node* b = new Node(3);
    // append(head,4);
    // append(head,5);
    // prepend(head,6);
    // insert(head,22,2);
    insert_tail(head,tail,7);
    insert_tail(head,tail,3);
    insert_tail(head,tail,56);
    delete_tail(head);
    count(head);   
    print_list(head);
    return 0;
}