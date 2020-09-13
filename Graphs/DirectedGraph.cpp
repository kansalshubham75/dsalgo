#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 9;
vector<vector<int>> graph(n, vector<int>());
void addEdge(int u, int v)
{
    graph[u].push_back(v);
}
void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int e : graph[i])
        {
            cout << e << " ";
        }
        cout << endl;
    }
}
//=======================TOPOLOGICAL SORT USING DFS(CYCLES NOT MANAGED)====================================
void topoDfsHelper(int src, vector<bool> &vis, vector<int> &st)
{
    vis[src] = true;
    for (int e : graph[src])
    {
        if (!vis[e])
            topoDfsHelper(e, vis, st);
    }
    st.push_back(src);
}
void topoDfs()
{
    vector<int> st; //stack for storing elements in post fashion
    vector<bool> vis(n, false);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            topoDfsHelper(i, vis, st);
        }
    }
    // cout<<st.size()<<endl;
    for (int i = n - 1; i >= 0; i--)
    {
        cout << st[i] << endl;
    }
}

//===================TOPO SORT USING DFS AND MANAGING CYCLES=========================//
bool topoDfsWithCycleHelper(int src, vector<bool> &vis, vector<int> &st, vector<bool> &cycle)
{
    vis[src] = cycle[src] = true;
    bool res = false;
    for (int e : graph[src])
    {
        if (!vis[e] && !res)
        {
            res = res || topoDfsWithCycleHelper(e, vis, st, cycle);
        }
        else if (cycle[e])
        {
            return true;
        }
    }
    cycle[src] = false;
    st.push_back(src);
    return res;
}
void topoDfsWithCycle()
{

    vector<bool> cycle(n, false);
    vector<int> st; //stack for storing elements in post fashion
    vector<bool> vis(n, false);
    bool res = false;
    for (int i = 0; i < graph.size() && !res; i++)
    {
        if (!vis[i])
        {
            res = res || topoDfsWithCycleHelper(i, vis, st, cycle);
        }
    }
    if (res)
    {
        st.clear();
        cout << "topo sort not possible";
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            cout << st[i] << endl;
        }
    }
}

//===================KAHN'S ALGO FOR TOPO SORT==================================//
void kahnsAlgo()
{
    vector<int> incidentEdges(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int e : graph[i])
        {
            incidentEdges[e]++;
        }
    }
    queue<int> q;
    queue<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (incidentEdges[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size() != 0)
    {
        int rvtx = q.front();
        q.pop();
        ans.push(rvtx);
        for (int e : graph[rvtx])
        {
            if (--incidentEdges[e] == 0)
                q.push(e);
        }
    }
    if (ans.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans.front() << endl;
            ans.pop();
        }
    }
    else
    {
        cout << "topo sort not possible";
    }
}
void createGraph()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 4);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 7);
    addEdge(2, 5);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 7);
    addEdge(4, 8);
    addEdge(5, 7);
    addEdge(6, 8);
    addEdge(7, 8);
}
int main()
{
    createGraph();
    display();
    // topoDfs();
    // topoDfsWithCycle();
    kahnsAlgo();
    return 0;
}
