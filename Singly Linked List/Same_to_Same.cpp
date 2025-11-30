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

int len(Node* head){
    int i=0;
    while (head!=NULL)
    {
        i++;
        head=head->next;
    }
    return i;
}

int compare_lists(Node *head1, Node *head2)
{
    int found = 0;
    int len_1 = len(head1);
    int len_2 = len(head2);
    if(len_1==len_2){

        while (head1 != NULL)
        {
            if (head1->val != head2->val)
            {
                found++;
                break;
            }
            head1 = head1->next;
            head2= head2->next;
            
        }
        if(found) return 0;
        else return 1;
    } else {
        return 0;
    }
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
    Node *head2 = NULL;
    Node *tail2 = NULL;
    while (true)
    {
        cin >> node;
        if (node == -1)
            break;
        insert_at_tail(head2, tail2, node);
    }
    if (compare_lists(head, head2))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}