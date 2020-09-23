#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
class Node{
    public:
    int val;
    Node* prev=NULL;
    Node* next=NULL;
    Node(int data){
        this->val=data;
    }
};
class DLL{
    public:
    int cap;
    Node* mid=NULL;
    Node* head=NULL;
    Node* tail=NULL;
    DLL(){
        cap=0;
    }
    void push(int val){
        if(cap==0){
            head=tail=mid=new Node(val);
        }else{
            tail->next=new Node(val);
            tail->next->prev=tail;
            tail=tail->next;
            if(cap%2==0)mid=mid->next;
        }
        cap++;
    }
    int pop(){
        if(cap==0)return -1;
        Node* tbd=tail;
        if(cap==1){
            tail=head=mid=NULL;
        }else{
            tail=tail->prev;
            tail->next->prev=NULL;
            tail->next=NULL;
            if(cap%2)mid=mid->prev;
        }
        cap--;
        return tbd->val;
    }
    int get_mid(){
        if(mid)return mid->val;
        return -1;
    }
};
void solve(){
    DLL* dll=new DLL();
    dll->push(10);
    dll->push(20);
    dll->push(30);
    dll->push(40);
    cout<<dll->get_mid();
    dll->push(50);
    cout<<dll->get_mid();
    dll->pop();
    cout<<dll->get_mid();
    dll->pop();
    dll->pop();
    dll->pop();
    dll->pop();
    dll->pop();
    dll->pop();
    cout<<dll->get_mid();

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}