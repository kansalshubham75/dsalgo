#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int cnttrue(string A) {
    vector<int> operands;
    vector<char> op;
    for(char c:A){
        if(c=='T'){
            operands.push_back(1);
        }else if(c=='F'){
            operands.push_back(0);
        }else{
            op.push_back(c);
        }
    }
    int n=operands.size();
    int t[n+1][n+1];
    int f[n+1][n+1];
    memset(t,0,sizeof(t));
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++){
            t[i][i]=operands[i]==1?1:0;
            f[i][i]=operands[i]==0?1:0;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //     cout<<t[i][j]<<" ";
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //     cout<<f[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int gap=1;gap<n;gap++){
        for(int l=0;l+gap<n;l++){
            int r=l+gap;
                cout<<l<<" "<<r<<endl;
                for(int cut=l;cut<r;cut++){
                    cout<<cut;
                    if(op[cut]=='&'){
                        cout<<" -> & \n";
                        t[l][r]+=(t[l][cut]*t[cut+1][r]);
                        f[l][r]+=(t[l][cut]*f[cut+1][r])+(f[l][cut]*t[cut+1][r])+
                                (f[l][cut]*f[cut+1][r]);
                    }else if(op[cut]=='|'){
                        cout<<" -> | \n";
                        t[l][r]+=(t[l][cut]*f[cut+1][r])+(f[l][cut]*t[cut+1][r])+
                                (t[l][cut]*t[cut+1][r]);
                        f[l][r]+=(f[l][cut]*f[cut+1][r]);
                    }else{
                        cout<<" -> ^ \n";
                        t[l][r]+=(t[l][cut]*f[cut+1][r])+(f[l][cut]*t[cut+1][r]);
                        f[l][r]+=(f[l][cut]*f[cut+1][r])+(t[l][cut]*t[cut+1][r]);
                    }
                    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<t[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<f[i][j]<<" ";
        cout<<endl;
    }
                }
                cout<<endl;
        }
    }
    // for(auto i:op)cout<<i<<" ";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<t[i][j]<<" ";
    //     cout<<"\n";
    // }
    return t[0][n-1];
}


int main(){
    cout<<cnttrue("F|T^T&F");
    return 0;
}