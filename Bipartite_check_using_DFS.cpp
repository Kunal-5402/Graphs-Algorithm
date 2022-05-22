#include<iostream>
#include<vector>
using namespace std;
bool bipartite_DFS(int i,vector<int> adjacency_list[],vector<int> &color)
{
    if(color[i]==-1)
    {
        color[i]==1;
    }
    for(auto it : adjacency_list[i])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[i];
            if(!bipartite_DFS(it,adjacency_list,color))
            {
                return false;
            }
        }
        else if(color[it]==color[i])
        {
            return false;
        }
    }
    return true;
}
bool check_bipartite(int V,vector<int> adjacency_list[])
{
    vector<int> color(V,-1);
    for(int i=0;i<=V;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartite_DFS(i,adjacency_list,color))
            {
                return false;
            }
        }
    }
    return true;
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
    if(check_bipartite(V,adjacency_list))
    {
        cout<<"The graph is biparite"<<endl;
    }
    else
    {
        cout<<"The graph is not biparite"<<endl;
    }
    return 0;
}