// 部落冲突问题
#include <iostream>
using namespace std;
#define MAX 666
int n, m;
int enemy[MAX][MAX];
int pick[MAX];
int best_team[MAX];
int max_num = 0;

// 判断这个人是否有敌人在队伍里
bool have_enemy(int p)
{
    for (int i = 1; i <= n; i++)
    {
        if (pick[i] == 1 && enemy[i][p] == 1)
            return true;
    }

    return false;
}

void Backtrack(int t)
{

    if (t == n + 1)
    {
        // 计算当前方案总人数
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            if (pick[i])
                num++;
        }
        // 更优解
        if (num > max_num)
        {
            max_num = num;
            for (int i = 1; i <= n; i++)
            {
                best_team[i] = pick[i];
            }
        }
        return;
    }

    // 选
    pick[t] = 1;
    int flag = 0;
    if (have_enemy(t)) // 此人有敌人
        flag = 1;
    if (!flag) // 剪枝
        Backtrack(t + 1);

    // 不选
    pick[t] = 0;
    Backtrack(t + 1); // 回溯

    return;
}

int main()
{

    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        enemy[u][v] = 1;
        enemy[v][u] = 1;
    }

    Backtrack(1);

    cout << max_num << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << best_team[i] << " ";
    }
}