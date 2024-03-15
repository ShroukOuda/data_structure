//undirected graph
#include <bits/stdc++.h>
using namespace std;
class representation
{
    private:
    list<int> adjlist[2000];
    public:
    void addedge(int u, int v)
    {
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    void printneighbors(int u)
    {
        cout<<"neighbors of vertix "<<u<<" : ";
        for (auto i:adjlist[u])
        cout<<i<<" ";
    }
    bool checkneighbors(int u, int v)
    {
        for (auto i:adjlist[u])
        {
            if (i == v)
            return true;
        }
        return false;
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
    graph.printneighbors(u);
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