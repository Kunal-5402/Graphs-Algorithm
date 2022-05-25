#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void find_topological_sort(int node,vector<int> &visited,stack<int> &s,vector<int> adjacency_list[])
{
    visited[node]=1;
    for(auto it : adjacency_list[node])
    {
        if(visited[it]==0)
        {
            find_topological_sort(it,visited,s,adjacency_list);
        }
    }
    s.push(node);
}
vector<int> topological_sort(int V,vector<int> adjacency_list[])
{
    vector<int> visited(V,0);
    stack<int> s;
    for(int i=1;i<=V;i++)
    {
        if(visited[i]==0)
        {
            find_topological_sort(i,visited,s,adjacency_list);
        }
    }
    vector<int> topo_sort;
    while(!s.empty())
    {
        topo_sort.push_back(s.top());
        s.pop();
    }
    return topo_sort;
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
    vector<int> topo_sort = topological_sort(V,adjacency_list);
    for(auto it : topo_sort)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}