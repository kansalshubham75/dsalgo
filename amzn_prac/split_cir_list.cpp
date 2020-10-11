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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node* s=head;
    Node* f=head;
    Node* sprev=NULL;
    Node* fprev=NULL;
    while(1){
        sprev=s;
        s=s->next;
        fprev=f->next;
        f=f->next->next;
        if(f==head || f->next==head)break;
    }
    if(f==head){
        s=sprev;
        f=fprev;
    }
    head1_ref=&head;
    head2_ref=&(s->next);
    s->next=*head1_ref;
    f->next=*head2_ref;
}

void solve(){
    
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