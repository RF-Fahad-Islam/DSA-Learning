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
        this->prev = NULL;
        this->next = NULL;
    }
};

class DoublyLL
{
public:
    Node *head;
    Node *tail;
    int size;
    DoublyLL()
    {
        this->head = NULL;
        this->tail = NULL;
        this-> size = 0;
    }

    void insert_at_head(int val)
    {
        Node *newnode = new Node(val);
        size++;
        if (this->head == NULL)
        {
            this->head = newnode;
            this->tail = newnode;
            return;
        }
        newnode->next = head;
        head->prev = newnode;
        this->head = newnode;
    }

    void insert_at_tail(int val)
    {
        Node *newnode = new Node(val);
        if (this->head == NULL)
        {
            insert_at_head(val);
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        this->tail = newnode;
        size++;
    }
    
    void delete_at_tail()
    {
        if(this->tail == NULL) return;
        Node *deleteNode = tail;
        Node *tmp = tail->prev;
        delete deleteNode;
        this->tail = tmp;
        if (tmp == NULL)
        {
            this->head = NULL;
            return;
        }
        tmp->next = NULL;
        size--;
    }
};

class Stack
{
public:
    DoublyLL L;
    void push(int val)
    {
        L.insert_at_tail(val);
    }
    int pop()
    {
        if (this->top() == -1)
            return -1;
        int val = this->top();
        L.delete_at_tail();
        return val;
    }
    int top()
    {
        if(L.tail == NULL) return -1;
        return L.tail->val;
    }
    int size()
    {
        return L.size;
    }
    bool empty()
    {
        return L.head == NULL;
    }
};

int main()
{
    Stack st;
    int n;
    cin >> n;
    while(n--){
        int val;
        cin>>val;
        st.push(val);
    }
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}