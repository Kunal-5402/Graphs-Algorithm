#include<iostream>
#include<vector>
using namespace std;
bool check_cycle_DFS(int node,vector<int> adjacency_list[],vector<int> &visited,vector<int> &DFSvisited)
{
    visited[node]=1;
    DFSvisited[node]=1;
    for(auto it : adjacency_list[node])
    {
        if(visited[it]==0)
        {
            if(check_cycle_DFS(it,adjacency_list,visited,DFSvisited))
            {
                return true;
            }
        }
        else if(DFSvisited[it])
        {
            return true;
        }
    }
    DFSvisited[node]=-1;
    return false;
}
bool is_cycle(int V,vector<int> adjacency_list[])
{
    vector<int> visited(V,0);
    vector<int> DFSvisited(V,0);
    for(int i=1;i<=V;i++)
    {
        if(visited[i]==0)
        {
            if(check_cycle_DFS(i,adjacency_list,visited,DFSvisited))
            {
                return true;
            }
        }
    }
    return false;
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
    }
    if(is_cycle(V,adjacency_list))
    {
        cout<<"The graph contains a cycle"<<endl;
    }
    else
    {
        cout<<"The graph does not contains a cycle"<<endl;
    }
    return 0;
}