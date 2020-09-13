#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void solve(){
    int n=1,a=1,b=1,c=1;
    cin>>n>>a>>b>>c;
    deque<int> q;
    if(n==1)
        cout<<1<<endl;
    for(int i=0;i<c;i++)
        q.push_back(n);
    a-=c;
    b-=c;
    if(a<0 || b<0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    int left=n-c-a-b;
    for(int i=0;i<left;i++){
        if(n-2<1){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        if(b>0)
            q.push_back(n-2);
        else
            q.push_front(n-2);
    }
    for(int i=0;i<a;i++){
        q.push_front(n-1);
    }
    for(int i=0;i<b;i++){
        q.push_back(n-1);
    }
    if(q.size()>n){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop_front();
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int c=1;
    int n;
    
    while(t--){
        cout<<"Case #"<<c++<<": ";
        solve();
    }
    return 0;
}