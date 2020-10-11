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
bool isPowof2(int n){
    int pc=__builtin_popcount(n);
    return pc==1 && !(n&1);
}
void reverse(vc<int>& arr,int l,int r){
    while(l<r){
        swap(arr[l],arr[r]);
        l++;r--;
    }
}
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
    }else if(n==3){
        cout<<"1 3 2"<<endl;
    }else if(isPowof2(n)){
        cout<<-1;
    }else{
        vc<int> arr(n+1);
        for(int i=0;i<=n;i++)arr[i]=i;
        arr[1]=2;arr[2]=3;arr[3]=1;
        int i=4;
        while(i<=n){
            if(isPowof2(arr[i])){
                swap(arr[i],arr[i+1]);
                i+=2;
            }else i++;
        }
        for(int i=1;i<=n;i++)if(arr[i]&arr[i-1]<=0){
            cout<<-1<<endl;return;
        }
        for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
    }
    cout<<endl;
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