#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edge;
};

class UnionFind {
    private:
        vector<int> parent, rank;
    public:
        UnionFind(int V) {
            parent.resize(V);
            rank.resize(V);
            for (int i = 0; i < V; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        int find(int i) {
            if (parent[i] != i) {
                parent[i] = find(parent[i]);
            }
            return parent[i];
        }
        void Union(int x, int y) {
            int xroot = find(x);
            int yroot = find(y);
            if (rank[xroot] < rank[yroot]) {
                parent[xroot] = yroot;
            } else if (rank[xroot] > rank[yroot]) {
                parent[yroot] = xroot;
            } else {
                parent[yroot] = xroot;
                rank[xroot]++;
            }
        }
};

bool comp(Edge a, Edge b) {
    return a.weight < b.weight;
}

Graph kruskalMST(Graph graph) {
    sort(graph.edge.begin(), graph.edge.end(), comp);
    Graph mst;
    mst.V = graph.V;
    mst.E = 0;
    UnionFind uf(graph.V);
    for (int i = 0; i < graph.E; i++) {
        int src = graph.edge[i].src;
        int dest = graph.edge[i].dest;
        int weight = graph.edge[i].weight;
        int x = uf.find(src);
        int y = uf.find(dest);
        if (x != y) {
            mst.E++;
            mst.edge.push_back({src, dest, weight});
            uf.Union(x, y);
        }
    }
    return mst;
}

int main() {
    Graph graph;
    graph.V = 4;
    graph.E = 5;
    graph.edge = { {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4} };

    Graph mst = kruskalMST(graph);

    cout << "Following are the edges in the constructed MST:" << endl;
    for (int i = 0; i < mst.E; i++) {
        cout << mst.edge[i].src << " -- " << mst.edge[i].dest << " : " << mst.edge[i].weight << endl;
    }
    return 0;
}


// Kruskal's algorithm in C++. The program creates a Graph struct that contains the number of vertices, the number of edges, and a vector of Edge structs. The Edge struct contains the source vertex, destination vertex, and weight of an edge.

// The UnionFind class is used to keep track of the connected components of the graph. It has a vector of parents and ranks for each vertex, and has methods for finding the root of a vertex and for merging two components.

// The kruskalMST() function first sorts the edges of the graph by weight using the STL sort() function. It then initializes an empty minimum spanning tree (MST) and an instance of the UnionFind class. The function uses a for loop to iterate through the edges of the graph. For each edge, it finds the roots of the source and destination vertices and checks if they are in the same component. If they are not, the edge is added to the MST and the two components are merged.

// The main function of the program initializes a sample graph and calls the kruskalMST() function to find the MST of the graph. The program then prints the edges of the MST.

// Overall, this program demonstrates how Kruskal's algorithm can be used to find the minimum spanning tree of a graph using UnionFind data structure.