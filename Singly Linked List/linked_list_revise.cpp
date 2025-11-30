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
    LinkedList(int val)
    {
        this->head = new Node(val);
    }

    void reverse(Node* head){
        if(head == NULL) return;
        reverse(head->next);
        printf("%d",head->val);
            if (this->head != head)
            {
                printf(" <- ");
            }
    }

    void print_reverse(){
        reverse(this->head);
    }

    void printLL()
    {
        while (this->head != NULL)
        {
            printf("%d", this->head->val);
            if (this->head->next != NULL)
            {
                printf(" -> ");
            }
            this->head = this->head->next;
        }
    }

    int len()
    {
        int i = 0;
        while (this->head != NULL)
            i++;
        return i;
    }

    // Adding Functions
    void prepend(int val)
    {
        // If not created any
        Node *newnode = new Node(val);
        newnode->next = this->head;
        this->head = newnode;
    }

    void attail(int val)
    {
        Node *newnode = new Node(val);
        Node *current = this->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }

    void atpos(int val, int pos)
    {
        Node *newnode = new Node(val);
        if (this->head == NULL)
        {
            this->head = newnode;
            return;
        }
        if (pos == 0)
        {
            newnode->next = this->head;
            this->head = newnode;
            return;
        }
        Node *current = this->head;
        for (int i = 0; i < pos - 1 && current->next != NULL; i++)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }

    // Delete
    void delhead()
    {
        Node *prevnode = this->head;
        this->head = this->head->next;
        delete prevnode;
    }

    void delpos(int pos)
    {
        if (pos == 0)
        {
            delhead();
        }

        Node *current = this->head;
        for (int i = 0; i < pos - 1 && current->next->next != NULL; i++)
        {
            current = current->next;
        }
        Node *node = current->next;
        current->next = node->next;
        delete node;
    }

    // Update
    void update(int val, int pos)
    {
        Node *current = this->head;
        for (int i = 0; i < pos && current != NULL; i++)
        {
            current = current->next;
        }
        current->val = val;
    }
};

int main()
{
    int n;
    cin >> n;
    // Node *this->head = new Node(0);
    // Node *a = new Node(1);
    // Node *b = new Node(2);
    // Node *c = new Node(3);
    // this->head->next = a;
    // a->next = b;
    // b->next = c;
    // prepend(this->head, 32);
    // attail(this->head, 33);
    // atpos(this->head, 45, 8);
    // delpos(this->head, 8);
    // update(this->head, 50, 2);
    // printLL(this->head);
    LinkedList *LL = new LinkedList(2);
    LL->prepend(10);
    LL->attail(2);
    LL->attail(5);
    LL->print_reverse();
    return 0;
}