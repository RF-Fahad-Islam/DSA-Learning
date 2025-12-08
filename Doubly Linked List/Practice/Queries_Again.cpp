#include <bits/stdc++.h>
using namespace std;
int len = 0;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    return;
}

void insert_any(Node *&head, Node *&tail, int pos, int val)
{
    if (pos == 0)
    {
        insert_at_head(head, tail, val);
        return;
    }
    Node *tmp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->next;
    }
    Node *newnode = new Node(val);
    newnode->next = tmp->next;
    if (tmp->next != NULL)
    {
        tmp->next->prev = newnode;
    }
    else
    {
        tail = newnode;
    }
    tmp->next = newnode;
    newnode->prev = tmp;
    return;
}

void L(Node *head)
{
    cout << "L -> ";
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void R(Node *tail)
{
    cout << "R -> ";
    while (tail)
    {
        cout << tail->val << " ";
        tail = tail->prev;
    }
    cout << endl;
}

int main()
{
    int q;
    cin >> q;
    Node *head = NULL;
    Node *tail = NULL;
    while (q--)
    {
        int x, v;
        cin >> x >> v;
        if (x >len)
        {
            cout << "Invalid" << endl;
        }
        else
        {
            insert_any(head, tail, x, v);
            len++;
            L(head);
            R(tail);
        }
    }
    return 0;
}
