// 最小机器重量问题
#include <iostream>
#include <climits>
using namespace std;
int n, m, d;
#define MAX 32
int c[MAX][MAX];
int w[MAX][MAX];
int sum_c = 0, sum_w = 0;
int choice[MAX], best_choice[MAX];
int min_w = INT_MAX;

void Backtrack(int t)
{
    if (t == n + 1)
    {
        // 更优解
        if (sum_w < min_w)
        {
            min_w = sum_w;
            for (int i = 1; i <= n; i++)
            {
                best_choice[i] = choice[i]; // 记录选择的厂商
            }
        }

        return;
    }

    // 每个厂商方案选一遍
    for (int i = 1; i <= m; i++)
    {
        sum_c += c[t][i];
        sum_w += w[t][i];
        choice[t] = i; // 记录选择
        // 剪枝，价格不超过d且重量还未超最优解
        if (sum_c <= d && sum_w < min_w)
        {
            Backtrack(t + 1);
        }
        sum_c -= c[t][i];
        sum_w -= w[t][i]; // 回溯
    }

    return;
}

int main()
{
    cin >> n >> m >> d;
    // 输入每个部件每个厂商的价格和重量
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    Backtrack(1);

    cout << min_w << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << best_choice[i] << " ";
    }
}