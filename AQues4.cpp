#include <iostream>
using namespace std;

class Dijkstra {
public:
    int n;
    int w[200][200];   
    int dist[200];
    int pi[200];
    int Q[200];

    void initGraph(int nodes) {
        n = nodes;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                w[i][j] = 0;   // no edge
    }

    void addEdge(int u, int v, int wt) {
        w[u][v] = wt;  // directed
    }

    void Initialize_Single_Source(int s) {
        for (int v = 0; v < n; v++) {
            dist[v] = 100000000;
            pi[v] = -1;
            Q[v] = 1;
        }
        dist[s] = 0;
    }

    int Extract_Min() {
        int minVal = 100000000, u = -1;
        for (int i = 0; i < n; i++)
            if (Q[i] == 1 && dist[i] < minVal) {
                minVal = dist[i];
                u = i;
            }
        return u;
    }

    void relax(int u, int v) {
        if (w[u][v] > 0 && dist[v] > dist[u] + w[u][v]) {
            dist[v] = dist[u] + w[u][v];
            pi[v] = u;
        }
    }

    int dijkstra(int s) {
        Initialize_Single_Source(s);

        while (true) {
            int u = Extract_Min();
            if (u == -1)
                break;

            Q[u] = 0;

            for (int v = 0; v < n; v++)
                relax(u, v);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == 100000000)
                return -1;   // unreachable
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};

int main() {
    int N, E;
    cin >> N >> E;

    Dijkstra G;
    G.initGraph(N);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G.addEdge(u-1, v-1, w);   // assuming nodes are 1-indexed
    }

    int K;
    cin >> K;

    cout << G.dijkstra(K-1);
}
