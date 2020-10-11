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
    int r1,r2,p1x,p1y,p1z,p2x,p2y,p2z,a1x,a1y,a1z,a2x,a2y,a2z;
    cin>>r1>>r2>>p1x>>p1y>>p1z>>a1x>>a1y>>a1z>>p2x>>p2y>>p2z>>a2x>>a2y>>a2z;
    int px=p1x-p2x,py=p1y-p2y,pz=p1z-p2z;
    int ax=a1x-a2x,ay=a1y-a2y,az=a1z-a2z;
    int adotp=ax*px+ay*py+az*pz;
    int adota=ax*ax+ay*ay+az*az;
    int t=max(0,-(adotp)/adota);
    int axt=ax*t,ayt=ay*t,azt=az*t;
    double dist=pow((r1+r2),2);
    double pvtx=pow(px+axt,2),pvty=pow(py+ayt,2),pvtz=pow(pz+azt,2);
    if((pvtx+pvty+pvtz)<=dist)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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