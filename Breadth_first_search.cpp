#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> BFS(int V, vector<int> adjacency_list[])
{
    vector<int> bfs;
    vector<int> visited(V+1,0);
    for(int i = 1; i<=V ;i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i]=1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it : adjacency_list[node])
                {
                    if(!visited[it])
                    {
                        q.push(it);
                        visited[it]=1;
                    }

                }
            }
        }
    }
    return bfs;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adjacency_list[V+1];
    for(int i = 1 ; i <= V ; i++ )
    {
        int u,v;
        cin>>u>>v;
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }
    vector<int>bfs = BFS(V,adjacency_list);
    for(auto it : bfs)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}