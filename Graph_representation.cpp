#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void adjacency_matrix()
{
    int V,E;
    cin>>V>>E;
    int adjacency_matrix[V+1][V+1];
    memset(adjacency_matrix,0,sizeof(adjacency_matrix));
    for(int i = 1; i<=V ; i++)
    {
        int u,v;
        cin>>u>>v;
        adjacency_matrix[u][v]=1;
        adjacency_matrix[v][u]=1;
    }
    cout<<endl;
    cout<<endl;
    for(int i = 1; i<=V ; i++)
    {
        for(int j = 0; j<=V ; j++)
            cout<<adjacency_matrix[i][j]<<" ";
        cout<<endl;
    }
}
void adjacency_list()
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
    for (int i = 1; i <= V; i++)
    {
        cout<<i<<"->";
        for (int j = 0; j < adjacency_list[i].size() ; j++)
        {
            cout<<adjacency_list[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    adjacency_matrix();
    adjacency_list();
    return 0;
}