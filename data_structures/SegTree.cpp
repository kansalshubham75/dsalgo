#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector

class segment_tree{
    vector<pair<ll,int>> st;
    int size;
    public:
    segment_tree(vc<ll>& arr){
        int n=arr.size();
        size=1;
        while(size<n)
            size*=2;
        st.resize(size*2,{0,0});
        init(arr,0,0,size);
    }

    ll fxn(int c,int d){
        if(d%2)
            return st[2*c+1].first|st[2*c+2].first;
        return st[2*c+1].first^st[2*c+2].first;
    }

    int init(vc<ll>& arr,int c,int lx,int rx){
        if(rx-lx==1){
            if(lx<arr.size())
                st[c].first=arr[lx];
            return 1;
        }
        int mid=lx+((rx-lx)/2);
        int d=init(arr,2*c+1,lx,mid);
        init(arr,2*c+2,mid,rx);
        st[c].second=d;
        st[c].first=fxn(c,d);
        return d+1;
    }
    void print(){
        for(auto& i:st)cout<<i.first<<" ";
        cout<<endl;
    }
    void set(int c,int i,int v,int lx,int rx){
        if(rx-lx==1){
            st[c].first=v;
            return;
        }
        int mid=lx+((rx-lx)/2);
        if(i<mid){
            set(2*c+1,i,v,lx,mid);
        }else{
            set(2*c+2,i,v,mid,rx);
        }
        st[c].first=fxn(c,st[2*c+1].second+1);
    }

    ll update(int i,ll v){
        set(0,i,v,0,size);
        return st[0].first;
    }

    // ll query(int c,int l,int r,int lx,int rx){
    //     if(lx>=r || rx<=l){
    //         return LLONG_MAX;
    //     }else if(lx>=l && rx<=r){
    //         return st[c].first;
    //     }
    //     int mid=lx+((rx-lx)/2);
    //     ll left=query(2*c+1,l,r,lx,mid);
    //     ll right=query(2*c+2,l,r,mid,rx);
    //     if(left==LLONG_MAX || r==LLONG_MAX)
    //         return min(left,right);
        
    // }
    // ll q(int l,int r){         //query
    //     return query(0,l,r,0,size);
    // }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vc<ll> arr(1<<n);
    for(int i=0;i<(1<<n);i++)
        cin>>arr[i];
    segment_tree st(arr);
    for(int i=0;i<m;i++){
        int x,v;
        cin>>x>>v;
        cout<<st.update(x-1,v)<<endl;
        // st.print();
    }
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