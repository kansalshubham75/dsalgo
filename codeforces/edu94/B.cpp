#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void solve(){
    int c1,c2;
    cin>>c1>>c2;
    int s,a;
    cin>>s>>a;
    int sw,aw;
    cin>>sw>>aw;
    if(sw>aw){
        swap(s,a);
        swap(sw,aw);
    }
    long long ans=0;
    for(int i=0;i<=s;i++){
        if((i*(long long)sw)>c1)
            continue;
        int hiss=min(s-i,c2/sw);
        int myleft=c1-(i*sw);
        int hisleft=c2-(hiss*sw);
        int mya=min(a,myleft/aw);
        int hisa=min(a-mya,hisleft/aw);

        ans=max(ans,1LL*(mya+i+hisa+hiss));
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}