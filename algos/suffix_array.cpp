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
void radix_sort(vc<pair<pii,int>>& a){
    int n=a.size();
    int count[n];
    memset(count,0,sizeof(count));
    for(auto& p:a){
        count[p.first.second]++;
    }
    int pos[n];
    pos[0]=0;
    for(int i=1;i<n;i++)pos[i]=pos[i-1]+count[i-1];

    vc<pair<pii,int>> a_new(n);
    for(auto& p:a){
        a_new[pos[p.first.second]]=p;
        pos[p.first.second]++;
    }
    a=a_new;

    memset(count,0,sizeof(count));
    for(auto& p:a){
        count[p.first.first]++;
    }
    pos[0]=0;
    for(int i=1;i<n;i++)pos[i]=pos[i-1]+count[i-1];
    for(auto& p:a){
        a_new[pos[p.first.first]]=p;
        pos[p.first.first]++;
    }
    a=a_new;
}
void solve(){
    string s;
    cin>>s;
    s+="$";
    int n=s.length();
    vc<pair<char,int>> a(s.length());
    for(int i=0;i<n;i++){
        a[i].first=s[i];
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    vc<int> p(n),c(n);      // p stores the positions of substrings of length 2^k after sorting  and 
                            // c[i] contains the equivalence class of any substring of length 2^k starting at index i 
    for(int i=0;i<n;i++){
        p[i]=a[i].second;
    }
    c[p[0]]=0;      
    for(int i=1;i<n;i++){
        if(a[i].first==a[i-1].first){
            c[p[i]]=c[p[i-1]];
        }else{
            c[p[i]]=c[p[i-1]]+1;
        }
    }
    int k=0;
    while(n>(1<<k)){
        //building array for iteration k+1
        vc<pair<pii,int>> arr(n);   //pii contains eq class for left and right part of a string of length 2^(k+1)
        for(int i=0;i<n;i++){
            arr[i].first={c[i],c[(i+(1<<k))%n]};    
            arr[i].second=i;
        }
        radix_sort(arr);    // sort on basis of pii
        for(int i=0;i<n;i++)p[i]=arr[i].second;
        c[p[0]]=0;
        for(int i=1;i<n;i++){
            if(arr[i].first==arr[i-1].first){
                c[p[i]]=c[p[i-1]];
            }else{
                c[p[i]]=c[p[i-1]]+1;
            }
        }
        k++;
    }
    
    for(int i:p)    cout<<i<<" ";
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