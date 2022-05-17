#include<iostream>
#include<vector>
using namespace std;
void DFS(int node,vector<int> & visited,vector<int> &dfs,vector<int>adjacency_list[])
{
    dfs.push_back(node);
    visited[node]=1;
    for(auto it : adjacency_list[node])
    {
        if(!visited[it])
        {
            DFS(it,visited,dfs,adjacency_list);
        }
    }
}
vector<int> DFS_components(int V, vector<int> adjacency_list[])
{
    vector<int> dfs;
    vector<int>visited(V+1,0);
    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
        {
            DFS(i,visited,dfs,adjacency_list);
        }
    }
    return dfs;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adjacency_list[V+1];
    for(int i=1;i<=E;i++)
    {
        int u,v;
        cin>>u>>v;
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }
    vector<int> dfs = DFS_components(V,adjacency_list);
    for(auto it : dfs)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}