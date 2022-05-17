#include<iostream>
#include<vector>
using namespace std;
bool check_for_cycle(int node,int previous_node,vector<int> &visited,vector<int> adjacency_list[])
{
    visited[node]=1;
    for(auto it : adjacency_list[node])
    {
        if(!visited[it])
        {
            if(check_for_cycle(it,node,visited,adjacency_list))
            {
                return true;
            }
        }
        else if(it!=previous_node)
        {
            return true;
        }
    }
    return false;
}
bool is_cycle(int V,vector<int> adjacency_list[])
{
    vector<int> visited(V+1,0);
    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
        {
            if(check_for_cycle(i,-1,visited,adjacency_list))
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
        adjacency_list[v].push_back(u);
    }
    if(is_cycle(V,adjacency_list))
    {
        cout<<"The graph contains a cycle."<<endl;
    }
    else
    {
        cout<<"The graph does not contains a cycle."<<endl;
    }
    return 0;
}