#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool check_for_cycle(int i,int V,vector<int> adjacency_list[],vector<int> &visited)
{
    queue<pair<int,int>> q;
    visited[i]=1;
    q.push({i,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int previous_node = q.front().second;
        q.pop();
        for(auto it : adjacency_list[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push({it,node}); 
            }
            else if(previous_node!=it)
            {
                return true;
            }
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
            if(check_for_cycle(i,V,adjacency_list,visited))
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
    for (int i = 1; i <= E; i++)
    {
        cout<<i<<"->";
        for (int j = 0; j < adjacency_list[i].size() ; j++)
        {
            cout<<adjacency_list[i][j]<<" ";
        }
        cout<<endl;
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