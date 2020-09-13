#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n=10;
int k=3;
int f=0;        //keeps track of next free space in st
vector<int> st(n);
vector<int> top(k,-1);
vector<int> nidx(n);
void push(int val,int sn){
    st[f]=val;
    int otop=top[sn];
    top[sn]=f;
    f=nidx[top[sn]];
    nidx[top[sn]]=otop;
}
void display(){
    cout<<"st : ";
    for(int i : st)
        cout<<i<<" ";
    cout<<endl<<"top : ";
    for(int i : top)
        cout<<i<<" ";
    cout<<endl<<"nidx : ";
    for(int i : nidx)
        cout<<i<<" ";
    cout<<endl;
}
int pop(int sn){
    if(top[sn]==-1)
        return -1;
    int ctop=top[sn];
    int retvalue=st[ctop];
    st[ctop]=0;
    top[sn]=nidx[ctop];
    nidx[ctop]=f;
    f=ctop;
    cout<<retvalue<<endl;
    return retvalue;
}

int main(){
    for(int i=0;i<n-1;i++)  nidx[i]=i+1;
    nidx[n-1]=-1;
    push(2,0);
    push(5,1);
    push(8,0);
    display();
    pop(1);
    display();
    pop(0);
    display();
    push(2,1);
    push(5,1);
    push(8,0);push(2,0);
    push(5,1);
    push(8,0);push(2,0);
    push(5,1);
    push(8,0);
    display();
    cout<<endl<<endl<<f;
    while(top[1]!=-1){
        pop(1);
    }
    display();
    return 0;
}