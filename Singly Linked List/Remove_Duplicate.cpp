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

void remove_duplicates(Node* &head,Node* &tail){
    if(head == NULL) return;
    for (Node* i = head; i!=NULL; i = i->next){
        for (Node* j = i; j->next!=NULL;)
        {
            if(i->val == j->next->val){
                Node* deleteNode = j->next;
                j->next = deleteNode->next;
                if(j->next == NULL){
                    tail = j;
                }
                delete deleteNode;
            } else {
                j= j->next;
            }
        }
        
    }
}

void print_ll(Node* head){
    while(head!=NULL){
        cout<< head->val << " ";
        head = head->next;
    }
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    int node;
    while (true)
    {
        cin >> node;
        if (node == -1)
            break;
        insert_at_tail(head, tail, node);
    }
   remove_duplicates(head,tail);
   print_ll(head);
    return 0;
}