/*
 * Program: Kruskal's Algorithm
 *
 * Kruskal's algorithm is a minimum-spanning-tree algorithm which finds an edge of the least possible weight that connects any two trees in the forest.
 * It is a greedy algorithm in graph theory as it finds a minimum spanning tree for a connected weighted graph adding increasing cost arcs at each step.
 * This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.
 * If the graph is not connected, then it finds a minimum spanning forest (a minimum spanning tree for each connected component).
 *
 * Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time.
 * After sorting, we iterate through all edges and apply find-union algorithm.
 * The find and union operations can take atmost O(LogV) time. So overall complexity is O(ELogE + ELogV) time.
 * The value of E can be atmost O(V2), so O(LogV) are O(LogE) same.
 * Therefore, overall time complexity is O(ElogE) or O(ElogV)
 * Space Complexity: O(E + V)
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0};
int mincost = 0;
int cost[10][10];

int find(int i){
    while (visited[i])
        i = visited[i];
    return i;
}

int uni(int i, int j){
    if (i != j){
        visited[j] = i;
        return 1;
    }
    return 0;
}

int main(){
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    cout << endl;
    while (ne < n){
        int min = 999;
        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                if (cost[i][j] < min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)){
            cout << "Edge " << ne << ": (" << a << " " << b << ") cost: " << min << endl;
            ne++;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << endl;
    cout << "Minimum cost = " << mincost << endl;

    return 0;
}

//write the output of the program here
/*
Enter the number of nodes: 6
Enter the adjacency matrix:
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0

Edge 1: (1 3) cost: 1
Edge 2: (4 6) cost: 2
Edge 3: (1 2) cost: 3
Edge 4: (2 5) cost: 3
Edge 5: (3 6) cost: 4

Minimum cost = 13
*/
