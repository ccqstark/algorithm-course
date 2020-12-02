// 0-1 背包 动态规划法
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1002
int c, n;
int dp[MAX][MAX];
int w[MAX];
int v[MAX];

int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int j = 1; j <= c; j++)
    {
        if (w[1] <= j)
            dp[1][j] = v[1];
    }

    for (int i = 1; i <= n; i++)
    {
        if (w[i] <= 1)
        {
            int temp = i;
            while (i <= n)
            {
                dp[i][1] = v[temp];
                i++;
            }
            break;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= c; j++)
        {
            if (w[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
            }
        }
    }

    cout << dp[n][c];
}
