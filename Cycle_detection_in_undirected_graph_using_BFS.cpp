#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool is_cyclic(int V,vector<int> adjacency_list[])
{
    vector<int> indegree(V+1,0);
    queue<int> q;
    for(int i=1;i<=V;i++)
    {
        for(auto it : adjacency_list[i])
        {
            indegree[it]++;
        }
    }
    for(int i=1;i<=V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int count = 0;
    vector<int> topo_sort;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo_sort.push_back(node);
        count++;
        for(auto it : adjacency_list[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    if(count==V)
    {
        return false;
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
    }
    if(is_cyclic(V,adjacency_list))
    {
        cout<<"The graph contains a cycle"<<endl;
    }
    else
    {
        cout<<"The graph does not contains a cycle"<<endl;
    }
    return 0;
}