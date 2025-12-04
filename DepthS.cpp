#include <iostream>
using namespace std ;

class Graph{
    public :
    int n ;
    int edges ;
    int adj[200][200];
    int colour[200] ;
    int parent[200] ;
    int time ;
    int f[200] ;
    int d[200] ;

    Graph(int vertices){
        n = vertices ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                adj[i][j] = 0 ;
            }
        }
    }
    void addEdge(int u , int v)
    {
        adj[u][v] = 1 ;
        adj[v][u] = 1 ;
    }
    void DFS_visit(int u)
    {
        time ++ ;
        d[u] = time ;
        colour[u] = 1 ;
        for(int v = 0 ; v < n ; v++)
        {
            if(adj[u][v] ==1)
            {
                if (colour[v] == 0)
                {
                    parent[v] = u ;
                    DFS_visit(v);
                }
            }
        }
        colour[u] = 2 ;
        time = time + 1 ;
        f[u] = time ;
    }  
    
    void DFS(){
        time = 0 ;
        for(int u = 0 ; u < n ; u++){
            colour[u] = 0 ;
            parent[u] = -1 ;
        }
        for(int u = 0 ; u < n ; u++)
        {
            if(colour[u] == 0)
            {
                DFS_visit(u);
            }
        }
    }
    void printResult(){
            for(int i = 0 ; i < n ; i++)
            {
                cout << i << " " << d[i] << " " << "finish" << " " << f[i] << parent[i] << endl ;
            }
        }
};
int main() {
    int n, edges;
    cin >> n;
    cin >> edges;

    Graph g(n);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.DFS();
    g.printResult();

    return 0;
}
