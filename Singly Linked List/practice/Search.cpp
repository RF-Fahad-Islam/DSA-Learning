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

int find_val(Node *head, int q)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->val == q)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
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
        int q;
        cin >> q;
        cout << find_val(head, q) << endl;
    }
    return 0;
}