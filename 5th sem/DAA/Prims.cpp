#include <iostream>
using namespace std;

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0};
int mincost = 0;
int cost[10][10];

int main()
{
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;
    cout << endl;
    while (ne < n)
    {
        int min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            cout << endl;
            cout << "Edge " << ne << ": (" << a << " " << b << ") cost: " << min;
            ne++;
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << endl;
    cout << "Minimum cost = " << mincost << endl;

    return 0;
}

//write output here
// Enter the number of nodes: 6
// Enter the adjacency matrix:
// 0 3 1 6 0 0
// 3 0 5 0 3 0
// 1 5 0 5 6 4
// 6 0 5 0 0 2
// 0 3 1 6 0 0
// 3 0 5 0 3 0
// 1 5 0 5 6 4
// 6 0 5 0 0 2

// Edge 1: (1 3) cost: 1
// Edge 2: (3 2) cost: 5
// Edge 3: (3 6) cost: 4
// Edge 4: (6 5) cost: 2
// Edge 5: (1 4) cost: 6

// Minimum cost = 18
