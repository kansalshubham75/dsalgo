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
void solve(){
    int n,x,p,k;
    cin>>n>>x>>p>>k;
    p--;k--;
    vc<int> arr(n);
    bool doesExist=false;
    int ans=-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==x)doesExist=true;
    }
    int replace=0;
    sort(arr.begin(),arr.end());
    if(!doesExist){
        replace=1;
        arr[k]=x;
        sort(arr.begin(),arr.end());
    }
    if(arr[p]==x){
        ans=replace;
    }else if(p<k){
        int leftOcc=-1;
        for(int i=0;i<p;i++)if(arr[i]==x)leftOcc=i;
        if(leftOcc==-1)ans=-1;
        else ans=p-leftOcc+replace;
    }else if(p>k){
        int rightOcc=-1;
        for(int i=n-1;i>p;i--)if(arr[i]==x)rightOcc=i;
        if(rightOcc==-1)ans=-1;
        else ans=rightOcc-p+replace;
    }else if(p==k){
        int rightOcc=-1;
        for(int i=n-1;i>p;i--)if(arr[i]==x)rightOcc=i;
        int leftOcc=-1;
        for(int i=0;i<p;i++)if(arr[i]==x)leftOcc=i;
        if(leftOcc!=-1)ans=p-leftOcc;
        else ans=rightOcc-p;
        ans+=replace;
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


    // sort(arr.begin(),arr.end());
    // if(arr[p]==x){
    //     ans=0;
    // }else if(doesExist){
    //     if(p<k){
    //         int leftOcc=-1;
    //         for(int i=0;i<p;i++)if(arr[i]==x)leftOcc=i;
    //         if(leftOcc!=-1)ans=p-leftOcc;
    //     }else if(p>k){
    //         int rightOcc=-1;
    //         for(int i=n-1;i>p;i--)if(arr[i]==x)rightOcc=i;
    //         if(rightOcc!=-1)ans=rightOcc-p;
    //     }else{
    //         int first=-1,second=-1;
    //         for(int i=0;i<n;i++){
    //             if(arr[i]==x){if(first==-1)first=i;
    //             second=i;}
    //         }
    //         if(first>p)ans=p-first;
    //         else ans=second-p;
    //     }
    // }else{
    //     if(p<k){
    //         if(arr[p]>x)ans=1;
    //     }else if(p>k){
    //         if(arr[p]<x)ans=1;
    //     }else{
    //         arr[p]=x;
    //         ans=0;
    //         int lessthanx=0;
    //         for(int i=0;i<n;i++)if(arr[i]<x)lessthanx++;
    //         if(lessthanx!=p)ans=abs(lessthanx-p);
    //     }
    // }
    // cout<<ans<<endl;