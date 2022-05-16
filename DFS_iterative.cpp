#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> DFS(int V,vector<int> adajacency_list[])
{
    vector<int> dfs;
    vector<int> visited(V+1,0);
    for(int i = 1 ; i<=V;i++)
    {
        if(!visited[i])
        {
            stack<int> s;
            s.push(i);
            visited[i]=1;
            while(!s.empty())
            {
                int node = s.top();
                s.pop();
                dfs.push_back(node);
                for(auto it : adajacency_list[node])
                {
                    if(!visited[it])
                    {
                        s.push(it);
                        visited[it]=1;
                    }
                }
            }
        }
    }
    return dfs;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adjacency_list[V+1];
    for(int i=1;i<=V;i++)
    {
        int u,v;
        cin>>u>>v;
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }
    vector<int> dfs = DFS(V,adjacency_list);
    for(auto it : dfs)
        cout<<it<<" ";
    cout<<endl;
}