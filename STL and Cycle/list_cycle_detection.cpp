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

bool cycle_detection(Node* head){
    Node* slow=head, *fast=head;
    while(fast->next!=NULL && fast!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) return true;
    }
    return false;
}

void print_forward(Node *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int node;
    while (cin >> node)
    {
        if(node==-1){
            tail->next = head;
            break;
        }
        insert_at_tail(head, tail, node);
    }
    if(cycle_detection(head)) cout << "Cycle";
    else cout << "No Cycle";

    return 0;
}