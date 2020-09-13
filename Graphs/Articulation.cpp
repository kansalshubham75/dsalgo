#include <iostream>
#include <vector>
using namespace std;
int n = 5;
int count=0;
vector<vector<int>> graph(5,vector<int>());
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void articulation_DFS(int u,int disc,vector<int>& low,vector<int>& dis,vector<bool>& vis){
for(int v:graph[u]){
    if(!vis[v]){
        vis[v]=true;
        low[v]=disc;
        dis[v]=disc;
        articulation_DFS(v,disc+1,low,dis,vis);
        if(low[v]>low[u]){
            count++;
            cout<<count;
        }
        low[v]=min(low[v],);
        return low[v];
    }else if(){
        
    }
}

}
int articulation(){
vector<int> low(n,0);
vector<int> dis(n,0);
vector<bool> vis(n,false);
int disc=0;
int calls=0;
for(int i=0;i<n;i++){
if(!vis[i]){
    calls++;
    vis[i]=true;
    articulation_DFS(i,disc+1,low,dis,vis);
}
}
if(calls==1){
count-=1;
}
}
int main(){
    addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3); 
    addEdge(3, 4);
    articulation();
    // for(vector<int> v:graph){
    //     for(int i:v){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<count;
}