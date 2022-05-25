// ALSO KNOWN AS KAHN'S ALGORITHM
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> topological_sort(int V,vector<int> adjacency_list[])
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
    vector<int> topo_sort;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo_sort.push_back(node);
        for(auto it : adjacency_list[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
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