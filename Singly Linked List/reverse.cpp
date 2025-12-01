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


void print_ll(Node* head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
}

Node* reverse(Node* &head,Node* &tail,Node* &tmp){
    if(tmp->next==NULL) {
        head = tmp;
        return ;
    }
    tmp->next = reverse(head,tail,tmp->next);
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

    return 0;
}