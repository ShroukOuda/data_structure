//undirected graph
#include <bits/stdc++.h>
using namespace std;
class representation
{
    private:
    bool adjmatrix[2000][2000];
    public:
    void addedge(int u, int v)//O(1)
    {
        adjmatrix[u][v] = 1;
        adjmatrix[v][u] = 1;
    }
    void printneighbors(int u, int n) //O(n) n------>no of nodes
    {
        cout<<"neighbors of vertex: "<<u<<" : ";
        for (int i = 0; i < n; i++)
        {
            if (adjmatrix[u][i])
            cout<<i<<" ";
        }
    }
    bool checkneighbors(int u, int v)//O(1)
    {
        return adjmatrix[u][v];
    }
};
int main()
{
    representation graph;
    int n, m, u, v;
    cout<<"enter no of nodes & edges: ";
    cin>>n>>m;//n -----> nodes, m -----> edges
    while (m--)//O(m)
    {
        cout<<"enter start & end vertex of edge: ";
        cin>>u>>v;
        graph.addedge(u, v);
    }
    cout<<"neighbors of vertex\n";
    int exit = 1;
    while(exit)
    {
    cout<<"enter vertex: ";
    cin>>u;
    graph.printneighbors(u, n);
    cout<<"\nif u want continue enter 1 othewise 0: ";
    cin>>exit;
    }
    cout<<"check neighbors\n";
    exit = 1;
    while (exit)
    {
        cout<<"enter u, v :";
        cin>>u>>v;
        if (graph.checkneighbors(u, v))
            cout<<"YES\n";
        else
            cout<<"NO\n";
        cout<<"if u want continue enter 1 otherwise 0: ";
        cin>>exit;
    }
}