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

class LinkedList
{
public:
    Node *head;
    Node* tail;
    LinkedList(Node *head = NULL)
    {
        this->head = head;
    }
    void insert_head(int val){
        Node *newnode = new Node(val);
        newnode->next = head;
        if (this->head == NULL){
            this->head = newnode;
            this->tail = newnode;
            return;
        }
        this->head = newnode;
    }

    int insert_ll(int val, int i)
    {
        if (i == 0)
        {
            insert_head(val);
            return 1;
        }
        Node *newnode = new Node(val);
        Node *tmp = this->head;
        i--;
        while (i--)
        {
            tmp = tmp->next;
            if (tmp == NULL)
            {
                return 0;
                break;
            }
        }
        newnode->next = tmp->next;
        tmp->next = newnode;
        if(tmp->next ==  NULL){
            this->tail = tmp;
        }
        return 1;

    }
    void insert_tail(int val){
        Node* newnode = new Node(val);
        if(this->head==NULL){
            this->head = newnode;
            this->tail = newnode;
            return;
        }
        this->tail->next = newnode;
        this->tail = newnode;
    }
    void print()
    {
        Node *tmp = this->head;
        while (tmp != NULL)
        {
            printf("%d", tmp->val);
            if (tmp->next != NULL)
            {
                printf(" -> ");
            }
            else
            {
                cout << endl;
            }
            tmp = tmp->next;
        }
    }
    void take_input()
    {
        int node;
        while (true)
        {
            cin >> node;
            if (node == -1)
                break;
            this->insert_tail(node);
        }
    }
};

int main()
{
    LinkedList *LL = new LinkedList(NULL);
    LL->take_input();
    int q;
    cin>>q;
    while (q--)
    {
        int i, val;
        cin >> i >> val;
        int inserted = LL->insert_ll(val, i);
        if (inserted)
        {
            LL->print();
        }
        else
        {
            printf("Invalid\n");
        }
    }
    return 0;
}