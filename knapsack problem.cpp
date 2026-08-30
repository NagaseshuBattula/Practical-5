#include <iostream>
using namespace std;

int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    int weight[100], profit[100];
    int dp[101][101] = {0};
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cout << "Enter profits of items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    // Knapsack calculation
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "\nMaximum Profit = " << dp[n][capacity];

    return 0;
}
