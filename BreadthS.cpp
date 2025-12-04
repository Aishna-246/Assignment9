#include <iostream>
using namespace std ;

class Graph{
    public :
    int n ;
    int edges ;
    int adj[200][200];
    int colour[200] ;
    int distance[200] ;
    int Q[200] ;
    int parent[200] ;

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
    
    void BFS(int s){
        for(int u = 0 ; u < n ; u++)
        {
            if(u != s)
            {
                colour[u] = 0 ;
                distance[u] = 99999 ;
                parent[u] = -1 ;
            }
            colour[s] = 1 ;
            distance[s] = 0 ;
            parent[s] = -1 ;

            int frontQ = 0 ;
            int rearQ = 0 ;
            Q[rearQ++] = s ;

            while(frontQ != rearQ){
                int u = Q[frontQ++];
            }
            for(int v = 0 ; v < n ; v++){
                if(adj[u][v]==1 && colour[v]==0){
                    colour[v] = 1;
                    distance[v] = distance[u] + 1 ;
                }
            }
        }
       
    }
    void printResult(){
            for(int i = 0 ; i < n ; i++)
            {
                cout << i << " " << distance[i] << " " << parent[i] << endl ;
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

    int s;
    cin >> s;

    g.BFS(s);
    g.printResult();

    return 0;
}
