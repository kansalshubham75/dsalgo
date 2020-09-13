#include <bits/stdc++.h>
using namespace std;
void solveLayer(int i,int j,int rot,int di,int dj,vector<vector<int>>& ans){
    int mod=2*(di+dj);
    rot%=mod;
    for(int c=j;c<j+dj;c++){
        int col=c;
        int row=i;
        if(rot>c+dj-1){
            rot-=
        }else{
            
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    vector<int> rot;
    int a;
    while(cin>>a)
        rot.push_back(a);
    vector<vector<int>> ans(m,vector<int>(n));
    return 0;
}