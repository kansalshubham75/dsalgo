#include <bits/stdc++.h>
using namespace std;
bool isFinished(double arr[4],double h){
    for(int i=0;i<4;i++){
        if(arr[i]!=h && arr[i]!=0)
            return false;
    }
    return true;
}
double mymin(double v1,double v2){
    if(v1<v2)
        return v1;
    return v2;
}
double mymax(double v1,double v2){
    if(v1>v2)
        return v1;
    return v2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double h;
    cin>>h;
    double pos[4];
    for(int i=0;i<4;i++)
        cin>>pos[i];
    double v[4];
    for(int i=0;i<4;i++)
        cin>>v[i];
    char dir[4];
    for(int i=0;i<4;i++)
        cin>>dir[i];
    double max_=0,min_=1e9;
    double diag=sqrt(2)*h;
    while(!isFinished(pos,h)){
        double abc,acd;
        double ab=sqrt((h*h)+((pos[0]-pos[1])*(pos[0]-pos[1])));
        double bc=sqrt((h*h)+((pos[1]-pos[2])*(pos[1]-pos[2])));
        double ac=sqrt((diag*diag)+((pos[0]-pos[2])*pos[0]*pos[2]));
        double ad=sqrt((h*h)+((pos[0]-pos[3])*(pos[0]-pos[3])));
        double cd=sqrt((h*h)+((pos[2]-pos[3])*(pos[2]-pos[3])));
        double s1=(ab+bc+ac)/2;
        double s2=(ad+cd+ac)/2;
        abc=sqrt(s1*(s1-ab)*(s1-bc)*(s1-ac));
        acd=sqrt(s2*(s2-ad)*(s2-cd)*(s2-ac));
        min_=min(min_,abc+acd);
        max_=max(max_,abc+acd);
        for(int i=0;i<4;i++)
            pos[i]=dir[i]=='U'?min(pos[i]+v[i],h):max(0.0,pos[i]-v[i]);
    }
        double abc,acd;
        double ab=sqrt((h*h)+((pos[0]-pos[1])*(pos[0]-pos[1])));
        double bc=sqrt((h*h)+((pos[1]-pos[2])*(pos[1]-pos[2])));
        double ac=sqrt((diag*diag)+((pos[0]-pos[2])*pos[0]*pos[2]));
        double ad=sqrt((h*h)+((pos[0]-pos[3])*(pos[0]-pos[3])));
        double cd=sqrt((h*h)+((pos[2]-pos[3])*(pos[2]-pos[3])));
        double s1=(ab+bc+ac)/2;
        double s2=(ad+cd+ac)/2;
        abc=sqrt(s1*(s1-ab)*(s1-bc)*(s1-ac));
        acd=sqrt(s2*(s2-ad)*(s2-cd)*(s2-ac));
        min_=min(min_,abc+acd);
        max_=max(max_,abc+acd);
        int ans1=4*max_*max_;
        int ans2=4*min_*min_;
        cout<<ans2<<" "<<ans1;
    return 0;
}