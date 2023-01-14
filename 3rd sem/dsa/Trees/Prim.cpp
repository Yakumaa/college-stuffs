#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int dest, weight;
};

struct Graph {
    int V;
    vector<vector<Edge>> adj;
};

class PrimMST {
    private:
        vector<bool> inMST;
        vector<int> dist, parent;
        Graph g;
        int V;
    public:
        PrimMST(Graph g) : g(g), V(g.V) {
            inMST.resize(V, false);
            dist.resize(V, INT_MAX);
            parent.resize(V, -1);
        }
        void primMST() {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            int src = 0;
            pq.push({0, src});
            dist[src] = 0;
            while (!pq.empty()) {
                int u = pq.top().second;
                pq.pop();
                inMST[u] = true;
                for (auto i : g.adj[u]) {
                    int v = i.dest;
                    int weight = i.weight;
                    if (!inMST[v] && dist[v] > weight) {
                        dist[v] = weight;
                        pq.push({dist[v], v});
                        parent[v] = u;
                    }
                }
            }
        }
        void printMST() {
            cout << "Edge :" << " Weight" << endl;
            for (int i = 1; i < V; i++)
                cout << parent[i] << " - " << i << " : " << dist[i] << endl;
        }
};

int main() {
    Graph g;
    g.V = 5;
    g.adj.resize(5);
    g.adj[0].push_back({1, 2});
    g.adj[0].push_back({3, 6});
    g.adj[0].push_back({4, 4});
    g.adj[1].push_back({2, 3});
    g.adj[2].push_back({3, 8});
    g.adj[2].push_back({4, 5});
    g.adj[3].push_back({4, 1});

    PrimMST primMST(g);
    primMST.primMST();
    primMST.printMST();

    return 0;
}

