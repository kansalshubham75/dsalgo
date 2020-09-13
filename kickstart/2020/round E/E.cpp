#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void solve(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    deque<int> q;
    if(n==2){
        if(c==2){
            if((a==2&&b==1)||(a==1&&b==2)){
                cout<<"IMPOSSIBLE"<<endl;
            }else{
                cout<<2<<" "<<2<<endl;
            }
            return;
        }else{
            if(a==2&&b==2){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }else{
                cout<<b<<" "<<a<<endl;
            }
            return;
        }
    }
    for(int i=0;i<c;i++)
        q.push_back(n);
    a-=c;
    b-=c;
    if(a<0 || b<0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    int left=n-c-a-b;
    // bool pad=0;
    for(int i=0;i<left;i++){
        if(b>0)
        q.push_back(1);
        else
        q.push_front(1);
    }
    for(int i=0;i<a;i++){
        q.push_front(2);
    }
    for(int i=0;i<b;i++){
        q.push_back(2);
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
    while(t--){
        cout<<"Case #"<<c++<<": ";
        solve();
    }
    return 0;
}