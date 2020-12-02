// 0-1 背包 回溯法
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 666
int c, n;
int cp;
int cw;
int bestp;

// 结构体存放商品
struct knapsack
{
    double singlep;
    double singlew;
    double per;
} good[MAX];

bool compare(knapsack a, knapsack b)
{
    return a.per > b.per;
}

// 按单价从大到小排序
void sort_by_perw()
{
    for (int i = 1; i <= n; i++)
    {
        good[i].per = good[i].singlep / good[i].singlew;
    }

    // 按单价排序
    sort(good + 1, good + n + 1, compare);

    return;
}

// 剪枝
int bound(int t)
{
    double leftw = c - cw;
    double b = cp;

    while (t <= n && good[t].singlew <= leftw)
    {
        leftw -= good[t].singlew;
        b += good[t].singlep;
        t++;
    }

    // 部分放入
    if (t < n)
    {
        b += leftw * good[t].per;
    }

    return b;
}

void Backtrack(int t)
{

    if (t > n)
    {
        if (cp > bestp)
        {
            bestp = cp;
        }

        return;
    }

    // 剪枝，判断是否会超过背包容量
    if (cw + good[t].singlew <= c)
    {
        cp += good[t].singlep;
        cw += good[t].singlew;
        // 选
        Backtrack(t + 1);
        cp -= good[t].singlep;
        cw -= good[t].singlew;
    }

    // 剪枝，判断是否有更优解
    if (bound(t + 1) > bestp)
    {
        // 不选
        Backtrack(t + 1);
    }

    return;
}

int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> good[i].singlew;
        cin >> good[i].singlep;
    }

    sort_by_perw();
    Backtrack(1);

    cout << bestp;

    return 0;
}
