#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
vector<int> shortest_path(vector<int> adjacency_list[],int source,int V)
{
    vector<int> distance(V+1,INT_MAX);
    queue<int> q;
    distance[source]=0;
    q.push(source);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it: adjacency_list[node])
        {
            if(distance[node]+1 < distance[it])
            {
                distance[it]=distance[node]+1;
                q.push(it);
            }
        }
    }
    return distance;
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
    vector<int> distance = shortest_path(adjacency_list,1,V);
    for (int i = 1; i <= V; i++)
    {
       cout<<distance[i]<<" ";
    }
    cout<<endl;
    return 0;
}