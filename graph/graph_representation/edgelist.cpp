//undirected graph
#include <bits/stdc++.h>
using namespace std;
class representation
{
    private:
    pair<int, int> edgelist[2000];
    int j = 0;
    public:
    void addedge(int u, int v)//O(1)
    {
        edgelist[j++] = {u, v};
    }
    void printneighbors(int u)//O(m) m----->no of edges
    {
        cout<<"neighbors of vertex "<<u<<" : ";
        for (int i = 0; i < j; i++)
        {
            if (edgelist[i].first == u)
                cout<<edgelist[i].second<<" ";
            else if (edgelist[i].second == u)
                cout<<edgelist[i].first<<" ";
        } 
    }
    bool checkneighbors(int u, int v)//O(m) m----->no of edges
    {
        for (int i = 0; i < j; i++)
        {
            if ((edgelist[i].first == u && edgelist[i].second == v)
            || (edgelist[i].second == u && edgelist[i].first == v))
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