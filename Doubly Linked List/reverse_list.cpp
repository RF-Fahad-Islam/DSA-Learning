#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_forward(Node *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

void reverse(Node *head, Node *tail)
{
    for (; head != tail && tail != head->prev; head=head->next, tail=tail->prev)
    {
        swap(head->val, tail->val);
    }
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(3);
    Node *b = new Node(4);
    Node *tail = new Node(1);
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = tail;
    tail->prev = b;
    reverse(head, tail);
    print_forward(head);
    return 0;
}