// 汽车加油问题
#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int station[1003];
    for (int i = 0; i <= k; i++)
    {
        cin >> station[i];
    }

    int times = 0, flag = 1;
    int oil = n;
    for (int i = 0; i <= k; i++)
    {
        if (oil > station[i])
            oil -= station[i];

        else
        {
            oil = n - station[i];
            // 加油后仍然不能到达下一个站点
            if (oil < 0)
            {
                flag = 0;
                break;
            }
            times++;
        }
    }

    if (!flag)
    {
        cout << "No Solution!";
    }
    else
    {
        cout << times;
    }

    return 0;
}