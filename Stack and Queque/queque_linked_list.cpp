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
    
  void delete_at_head(){
    Node* deleteNode = head;
    this->head = head->next;
    delete deleteNode;
    if(head==NULL){
        this->tail = NULL;
        return;
    }
    head->prev = NULL;

  }
};

class SinglyLL
{
public:
    Node *head;
    Node *tail;
    int size;
    SinglyLL()
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
        this->tail = newnode;
        size++;
    }
    
  void delete_at_head(){
    Node* deleteNode = head;
    this->head = head->next;
    delete deleteNode;
    if(head==NULL){
        this->tail = NULL;
    }

  }
};

class QuequeDLL
{
public:
    DoublyLL L;
    void push(int val)
    {
        L.insert_at_tail(val);
    }
    int pop()
    {
        if (this->front() == -1)
            return -1;
        int val = this->front();
        L.delete_at_head();
        return val;
    }
    int front()
    {
        if(L.head == NULL) return -1;
        return L.head->val;
    }
    int back()
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

class QuequeSLL
{
public:
    SinglyLL L;
    void push(int val)
    {
        L.insert_at_tail(val);
    }
    int pop()
    {
        if (this->front() == -1)
            return -1;
        int val = this->front();
        L.delete_at_head();
        return val;
    }
    int front()
    {
        if(L.head == NULL) return -1;
        return L.head->val;
    }
    int back()
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
    QuequeDLL st;
    int n;
    cin >> n;
    while(n--){
        int val;
        cin>>val;
        st.push(val);
    }
    while(!st.empty()){
        cout << st.front() << endl;
        st.pop();
    }
}