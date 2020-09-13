#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

Node* createList(vector<int>& arr)
{
    int n=arr.size();
    Node *head = NULL;
    Node *temp = head;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        
        Node *node = new Node(x);
        if (head == NULL)
        {
            head = node;
            temp = head;
        }
        else
        {
            temp->next = node;
            temp = temp->next;
        }
    }

    return head;
}
Node *reverse(Node *l)
{
    Node *curr = l;
    Node *prev = NULL;
    

    while (curr != NULL)
    {
        
        Node *forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    
    return prev;
}

Node *solve(Node *list1, Node *list2)
{
    // cout<<list1->val;
    Node *l1 = reverse(list1);
    Node *l2 = reverse(list2);
    int c = 0;
    Node* head=NULL;
    Node* temp=NULL;
    while (l1 != NULL && l2 != NULL)
    {
        
        int ans = l1->val + l2->val + c;
        c=ans/10;
        ans=ans%10;
        Node* n=new Node(ans);
        if(head==NULL){
            head=n;
            temp=n;
        }else{
            temp->next=n;
            temp=temp->next;
        }
        l1=l1->next;
        l2=l2->next;
    }
    while(l1!=NULL){
        int ans = l1->val + c;
        c=ans/10;
        ans=ans%10;
        Node* n=new Node(ans);
        temp->next=n;
        temp=temp->next;
        l1=l1->next;
    }
    while(l2!=NULL){
        int ans = l2->val + c;
        c=ans/10;
        ans=ans%10;
        Node* n=new Node(ans);
        temp->next=n;
        temp=temp->next;
        l2=l2->next;
    }
    return reverse(head);
}

void display(Node *node)
{
    while (node != NULL)
    {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    vector<int> one={1,2,3,4};
    vector<int> two={4,5,6};
        Node *l1 = createList(one);
        Node *l2 = createList(two);
        Node* ans = solve(l1, l2);
        display(ans);
    return 0;
}