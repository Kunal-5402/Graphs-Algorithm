#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool bipartite_BFS(int i,vector<int> adjacency_list[],vector<int> &color)
{
    queue<int> q;
    q.push(i);
    color[i]=1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adjacency_list[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            {
                return false;
            }
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
            if(!bipartite_BFS(i,adjacency_list,color))
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
        cout<<"The Graph is Bipartite"<<endl;
    }
    else
    {
        cout<<"The Graph is Not Bipartite"<<endl;
    }
    return 0;
}