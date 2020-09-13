#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Edge
{
public:
    int v;
    int w;
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};
int n = 7;
vector<Edge *> graph[7];
void addEdge(int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}
void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (Edge *e : graph[i])
        {
            cout << "(" << e->v << "," << e->w << ")" << " ";
        }
        cout << endl;
    }
}
int searchVertex(int u, int v)
{
    int idx = -1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i]->v == v)
        {
            idx = i;
            break;
        }
    }
    return idx;
}
void removeEdge(int u, int v)
{
    int uvtx=searchVertex(v,u);
    int vvtx=searchVertex(u,v);
    if(uvtx!=-1){
        graph[u].erase(graph[u].begin()+vvtx);
        graph[v].erase(graph[v].begin()+uvtx);
    }
}
bool hasPath(int src,int dest,vector<bool>& vis,string ans){
    if(src==dest){
        cout<<ans;
        return true;
    }
    bool res=false;
    vis[src]=true;
    for(Edge* e:graph[src]){
        if(!vis[e->v])
        res=res||hasPath(e->v,dest,vis,ans+" "+to_string(src));
    }
    return res;
}
int allPath(int src,int dest,vector<bool>& vis,string ans){
    if(src==dest){
        cout<<ans;
        return 1;
    }
    // bool res=false;
    int count=0;
    vis[src]=true;
    for(Edge* e:graph[src]){
        if(!vis[e->v])
        count+=hasPath(e->v,dest,vis,ans+" "+to_string(src));
    }
    vis[src]=false;
return count;
}
// int hamiltonianPathAndCycle(int src,int osrc,vector<bool>& vis,string ans,int count){
//     if(count==n){                   //count==n if passing count=1 when calling else count==n-1 if passing 0
//         ans=ans+" "+to_string(src);
//         int vtx=searchVertex(src,osrc);
//         if(vtx!=-1){
//             cout<<"Cycle: "<<ans<<endl;
//         }else{
//             cout<<"Path: "<<ans<<endl;
//         }
//         return 1;
//     }
//     // bool res=false;
//     int count=0;
//     vis[src]=true;
//     for(Edge* e:graph[src]){
//         if(!vis[e->v])
//         count+=hamiltonianPathAndCycle(e->v,osrc,vis,ans+" "+to_string(src),count+1);
//     }
// vis[src]=false;
// return count;
// }
void BFS(int src,vector<bool>& vis){
    queue<int> que;
    que.push(src);
    int level=0;
    while(que.size()>0){
        int size=que.size();
        while(size-->0){
            int rvtx=que.front();
            que.pop();
            if(vis[rvtx]){
                cout<<"Cycle wrt: "<<src<<" "<<rvtx;
                continue;
            }
            vis[rvtx]=true;
            for(Edge* e:graph[rvtx]){
                if(!vis[e->v]){
                    que.push(e->v);
                }
            }
        }
        level++;
    }
}
bool bipartite(int src,vector<int>& vis){
queue<pair<int,int>> que;
que.push({src,0});
while(que.size()>0){
    int size=que.size();
    while(size-->0){
        pair<int,int> rpair=que.front();
        que.pop();
        int u=rpair.first;
        int c=rpair.second;
        if(vis[u]!=-1){
            if(c!=vis[u])
                return false;
            else
            {
                continue;
            }
            
        }
        vis[u]=c;
        for(Edge* e:graph[u]){
            if(vis[e->v==-1])
            que.push({e->v,(c+1)%2});
        }
    }
}
}

void dijstraAlgo(){
    vector<vector<int>> graph={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                                { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                                { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                                { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                                { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                                { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});             //first= weightsofar,second=vertex
    vector<int> vis(graph.size(),-1);
    while(!pq.empty()){
        pair<int,int> rp=pq.top();
        pq.pop();
        int u=rp.second;
        int w=rp.first;

        if(vis[u]==-1){
            vis[u]=w;
            for(int i=0;i<graph.size();i++){
                if(graph[u][i]!=0 && vis[i]==-1)
                    pq.push({graph[u][i]+w,i});
            }
        }
    }
for(int i=0;i<vis.size();i++)
    cout<<i<<" -> "<<vis[i]<<endl;
}
int main()
{
    dijstraAlgo();
    return 0;
}