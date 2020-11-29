// 满减金额
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int price[102];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i]; // 输入价格
    }

    // 填表矩阵
    int count[101][1001]; // i: 选择范围是前i个商品  j：当前满减金额为j

    // 初始化
    for (int i = 0; i <= m; i++)
    {
        if (i <= price[0])
        {
            count[0][i] = price[0];
        }
        else
        {
            count[0][i] = 9999999; // 初始化为最大值
        }
    }

    // 填表
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // 当前满减金额比当前单个商品价格还小
            if (j <= price[i])
            {
                // 选这个单个商品，或不选
                count[i][j] = min(price[i], count[i - 1][j]);
            }
            else
            {
                // 选择这个商品, 对应的就是price[i] + count[i - 1][j - price[i]]
                // 选与不选的最小值
                count[i][j] = min(price[i] + count[i - 1][j - price[i]], count[i - 1][j]);
            }
        }
    }

    int ans = count[n - 1][m];
    // 无解
    if (ans == 9999999)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}