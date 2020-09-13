#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin>>x>>y;
    int n;
    cin>>n;
    if(x>y){
        int temp=x;
        x=y;
        y=temp;
    }
    vector<double> sp(n);
    for(int i=0;i<n;i++)
        cin>>sp[i];
    vector<double> movx(n,0);
    vector<double> movy(n,0);
    double sum=0;
    for(int i=0;i<x;i++)
        sum+=sp[i];
    movx[x-1]=sum/x;
    for(int i=x;i<n;i++){
        sum=sum-sp[i-x];
        sum=sum+sp[i];
        movx[i]=sum/x;
    }
    sum=0;
    for(int i=0;i<y;i++)
        sum+=sp[i];
    movy[y-1]=sum/y;
    for(int i=y;i<n;i++){
        sum=sum-sp[i-y];
        sum=sum+sp[i];
        movy[i]=sum/y;
    }
    int ans=0;
    for(int i=y-1;i<n;i++){
        if(movx[i]==movy[i]){
            ans++;
        }else if(movx[i-1]<movy[i-1] && movx[i]>movy[i]){
            ans++;
        }else if(movx[i-1]>movy[i-1] && movx[i]<movy[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
