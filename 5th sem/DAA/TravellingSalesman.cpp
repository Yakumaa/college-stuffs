/*
 *
 * Problem: Travelling Salesman Problem
 *
 * Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.
 *
 * Time Complexity: O(n^2 * 2^n)
 * Space Complexity: O(n * 2^n)
 *
 */

#include <iostream>
#include <climits>
using namespace std;
#define MAX 9999

int n, cost[MAX][MAX], dp[MAX][MAX];

int tsp(int, int);

int main(){
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }

    int start = 0;
    cout << "Minimum cost of the Travelling Salesman Tour = " << tsp(start, (1 << start)) << endl;

    return 0;
}

int tsp(int start, int mask){
    if (mask == (1 << n) - 1){
        return cost[start][0];
    }

    if (dp[start][mask] != 0){
        return dp[start][mask];
    }

    int minCost = INT_MAX;
    for (int end = 0; end < n; end++){
        if ((mask & (1 << end)) == 0){
            int newCost = cost[start][end] + tsp(end, mask | (1 << end));
            minCost = min(minCost, newCost);
        }
    }

    return dp[start][mask] = minCost;
}

//write output of the code here
// Enter the number of cities: 4
// Enter the cost matrix:
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0
// Minimum cost of the Travelling Salesman Tour = 80
