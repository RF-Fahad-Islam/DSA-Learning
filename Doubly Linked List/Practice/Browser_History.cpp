#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string val;
    Node *next;
    Node *prev;
    Node(string val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, string val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    return;
}

Node *visit(Node *head, string search)
{
    Node *tmp = head;
    while (tmp)
    {
        if (tmp->val == search)
            return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}

Node *next(Node *point_to)
{
    return point_to->next;
}
Node *prev(Node *point_to)
{
    return point_to->prev;
}

int main()
{
    string v;
    Node *head = NULL;
    Node *tail = NULL;
    while (cin >> v && v != "end")
    {
        insert_at_tail(head, tail, v);
    }
    int q;
    cin >> q;
    Node *point_to = nullptr;
    while (q--)
    {
        string query, search;
        cin >> query;
        bool available = false;
        if (query == "visit")
        {
            cin >> search;
            Node *visited = visit(head, search);
            if (visited)
            {
                point_to = visited;
                available = true;
            }
            else
                available = false;
        }
        else if (query == "next")
        {
            if (point_to->next == NULL)
                available = false;
            else
            {
                point_to = next(point_to);
                available = true;
            }
        }
        else if (query == "prev")
        {
            if (point_to->prev == NULL)
                available = false;
            else
            {
                point_to = prev(point_to);
                available = true;
            }
        }
        if (available)
            cout << point_to->val;
        else
            cout << "Not Available";
        cout << endl;
    }
    return 0;
}
