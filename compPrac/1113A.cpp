#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,v;
    cin>>n>>v;
    int cost=0,curr=0;
    int i=1;
    while(i<n){
        if(i+curr<n){
            if(v<(n-i)){
                cost+=(i*(v-curr));
                curr=v;
            }else{
                cost+=(i*(n-i-curr));
                curr=(n-i);
            }
        }
        curr--;
        i++;
    }
    cout<<cost;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}