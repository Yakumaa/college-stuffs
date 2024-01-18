/*
 * Program: 0/1 Knapsack Problem
 *
 * The 0/1 knapsack problem is a combinatorial optimization problem where we have a set of items, each with a weight and a value,
 * and we need to determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
using namespace std;

int knapsack(int, int[], int[], int);

int main(){
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    int val[n], wt[n];
    cout << "Enter the value and weight of each item: ";
    for (int i = 0; i < n; i++)
        cin >> val[i] >> wt[i];

    cout << "Maximum value we can obtain = " << knapsack(W, wt, val, n);

    return 0;
}

/*
 * This function calculates the maximum value that can be obtained from the given items
 *
 * @param W - capacity of knapsack
 * @param wt - array of weights
 * @param val - array of values
 * @param n - number of items
 *
 * @returns maximum value that can be obtained from the given items
 */

int knapsack(int W, int wt[], int val[], int n){
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= W; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}


