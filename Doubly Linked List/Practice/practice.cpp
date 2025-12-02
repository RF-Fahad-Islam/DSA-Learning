#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node (int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class DoublyLL{
    public:
    Node* head;
    Node* tail;
    DoublyLL(Node* head=NULL){
        this->head=NULL;
        this->tail=NULL;
    }

    void insert_at_head(int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head = newnode;
            tail = newnode;
            return;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    void insert_at_tail(int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    int insert_at_any(int pos,int val){
        if(pos==0){
            this->insert_at_head(val);
            return 1;
        }
        if(this->len()<pos) return 0;
        Node* newnode = new Node(val);
        Node* tmp = this->head;
        for (int i = 0; i < pos-1; i++)
        {
            if(tmp==NULL) return 0;
            tmp = tmp->next;
        }
        newnode->next = tmp->next;
        tmp->next= newnode;
        newnode->prev = tmp;
        // Change tail if insert at tail position
        if(newnode->next == NULL){
            this->tail = newnode; 
            return 1;
        }
        newnode->next->prev = newnode;
        return 1;
    }

    void take_input(){
        int node;
        while(cin>>node && node != -1){
            this->insert_at_tail(node);
        }
    }

    void print_forward(){
        Node* tmp = this->head;
        while(tmp){
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout<<endl;
    }

    void print_backward(){
        Node* tmp = this->tail;
        while(tmp){
            cout << tmp->val << " ";
            tmp = tmp->prev;
        }
        cout<<endl;
    }
    
    int len(){
        int i = 0;
        Node* tmp = this->head;
        while(tmp){
            i++;
            tmp = tmp->next;
        }
        return i;
    }

    bool is_same(DoublyLL* ll2){
        if(this->len() != ll2->len()) return false;
        for(Node *tmp = this->head, *tmp2 = ll2->head; tmp;tmp=tmp->next,tmp2=tmp2->next){
            if(tmp->val!=tmp2->val) return false;
        }
        return true;
    }

    void reverse(){
        for (Node* i = this->head,*j=this->tail; i!=j && i->prev!=j; i=i->next,j=j->prev){
            swap(i->val,j->val);
        }
    }
    
    bool is_palindrome(){
        for (Node* i = this->head,*j=this->tail; i!=j && i->prev!=j; i=i->next,j=j->prev){
            if(i->val!=j->val) return false;
        }
        return true;
    }

    void asc_sort(){
        for (Node* i = this->head; i->next != NULL; i=i->next)
        {
            for (Node* j = i->next; j != NULL ; j=j->next)
            {
                if(i->val>j->val){
                    swap(i->val,j->val);
                }
            }
            
        }
        
    }
};


int main(){
    // Problem-1: Is Same
    DoublyLL* ll1 =new DoublyLL();
    DoublyLL* ll2 =new DoublyLL();
    ll1->take_input();
    ll2->take_input();
    if(ll1->is_same(ll2)) cout<<"YES";
    else cout<<"NO";
    cout<<endl;

    //Problem-2: Reverse List
    ll1->reverse();
    ll1->print_forward();

    // Problem-3: Is Palindrome
    if(ll1->is_palindrome()) cout<< "YES";
    else cout << "NO";
    cout << endl;

    // Problem-4: Insert at query positions
    DoublyLL* ll3 = new DoublyLL();
    int q;
    cin>>q;
    while(q--){
        int x,v;
        cin>>x>>v;
        int insert = ll3->insert_at_any(x,v);
        if(!insert) cout<<"Invalid"<<endl;
        else {
            ll3->print_forward();
            ll3->print_backward();
        }
    }
    // Problem-5 : Ascending sort
    DoublyLL* ll4 = new DoublyLL();
    ll4->take_input();
    ll4->asc_sort();
    ll4->print_forward();
    return 0;
}