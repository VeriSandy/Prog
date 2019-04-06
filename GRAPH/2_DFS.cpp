

//Depth First Search or DFS for a Graph
//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

/*
    Depth First Search is like inorder traversal
    start with a node n and look for one adjacent element
    start with that adjacent until nothing left
    now come back to n, look for another adjacent node 
    and go on
*/

#include <iostream>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS();
    void DFSUtil(int i, bool *v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    return;
}


void Graph::DFSUtil(int i, bool *v)
{
    v[i] = true;
    cout << i << " ";

    list<int>::iterator j;
    for(j = adj[i].begin(); j != adj[i].end(); j++)
    {
        if(v[*j] == false)
            DFSUtil(*j, v);
    }

    return;
}

void Graph::DFS()
{
    bool *vis = new bool[V];
    int i = 0;
    for(; i< V; i++)
        vis[i] = false;

    for(i = 0; i < V; i++)
        if(vis[i] == false)
            DFSUtil(i, vis);
    return;
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(4, 4);

    cout << "Following is Depth First Traversal: ";
    g.DFS();

    cout << "\n";

    return 0;
}
