#include <iostream>
using namespace std;

class Dijkstra {
public:
    int n;
    int w[20][20];
    int dist[20];
    int visited[20];
    int pq[20][20];
    int pi[20];
    int S[20];
    int Q[20];

    void readGraph() {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> w[i][j];
    }

    void Initialize_Single_Source(int s) {
        for (int v = 0; v < n; v++) {
            dist[v] = 1000000;
            pi[v] = -1;
        }
        dist[s] = 0;
    }

    int Extract_Min() {
        int minVal = 1000000, u = -1;
        for (int i = 0; i < n; i++)
            if (Q[i] == 1 && dist[i] < minVal) {
                minVal = dist[i];
                u = i;
            }
        return u;
    }

    void relax(int u, int v) {
        if (dist[v] > dist[u] + w[u][v]) {
            dist[v] = dist[u] + w[u][v];
            pi[v] = u;
        }
    }

    void dijkstra(int s) {
        Initialize_Single_Source(s);

        for (int i = 0; i < n; i++) {
            S[i] = 0;
            Q[i] = 1;
        }

        while (true) {
            int u = Extract_Min();
            if (u == -1)
                break;

            Q[u] = 0;
            S[u] = 1;

            for (int v = 0; v < n; v++) {
                if (w[u][v] > 0)
                    relax(u, v);
            }
        }
    }

    void printResult() {
        for (int i = 0; i < n; i++)
            cout << "vertex " << i
                 << " : distance = " << dist[i]
                 << ", pi = " << pi[i] << endl;
    }
};

int main() {
    Dijkstra G;
    G.readGraph();
    int s;
    cin >> s;
    G.dijkstra(s);
    G.printResult();
    return 0;
}
