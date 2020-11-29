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
        cin >> price[i];
    }

    int count[101][1001];
    for (int i = 0; i <= m; i++)
    {
        if (i <= price[0])
        {
            count[0][i] = price[0];
        }
        else
        {
            count[0][i] = 9999999;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j <= price[i])
            {
                count[i][j] = min(price[i], count[i - 1][j]);
            }
            else
            {
                count[i][j] = min(price[i] + count[i - 1][j - price[i]], count[i - 1][j]);
            }
        }
    }

    int ans = count[n - 1][m];
    if (ans == 9999999){
        cout<<-1;
    }else{
        cout<<ans;
    }

}