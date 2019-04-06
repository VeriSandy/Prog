
//Breadth First Search or BFS for a Graph
//https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

//we are using adjacnecy matrix implementation
//this  is for connected graph, need modification for disconnected graph

#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
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

void Graph::BFS(int s)
{
    bool *vis = new bool[V];
    int i = 0;
    for(; i < V; i++)
        vis[i] = false;
   
    list<int>que;
    vis[s] = true;
    que.push_back(s);

    list<int>::iterator j;

    while(!que.empty())
    {
        s = que.front();
        cout << s << " ";
        que.pop_front();
        for(j = adj[s].begin(); j != adj[s].end(); j++)
        {
            if(!vis[*j])
            {
                que.push_back(*j);
                vis[*j] = true;
            }
        }
    }
    return;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    cout << "\n";
    return 0;
}
