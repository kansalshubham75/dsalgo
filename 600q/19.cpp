#include <bits/stdc++.h>
using namespace std;
void solve(){
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr;
    int n;
    unordered_map<int,int> m;
    m[0]=-1;
    int max_=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i]==0?-1:1;
        if(m.find(sum)!=m.end())
            max_=max(max_,i-m[sum]);
        else
            m[sum]=i;
    }
    return max_;
    return 0;
}