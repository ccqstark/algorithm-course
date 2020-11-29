// 最优调度问题
#include <iostream>
#include <climits>
using namespace std;
#define MAX 666
int n, k;
int arr[MAX];
int sign[MAX];
int min_time = INT_MAX;
int mach[22];

void Backtrack(int t)
{
    // 剪枝
    for (int i = 1; i <= k; i++)
    {
        if (mach[i] > min_time)
            return;
    }

    if (t == n + 1)
    {
        int one_time = 0;
        for (int i = 1; i <= k; i++)
        {
            if (mach[i] > one_time)
                one_time = mach[i]; // 最大的时间用来作为此种安排的所需总时间
        }
        if (one_time < min_time)
            min_time = one_time; // 找最优
        return;
    }

    for (int i = 1; i <= k; i++) // 每个任务都有放入k个机器的k种情况
    {
        mach[i] += arr[t];
        Backtrack(t + 1);
        mach[i] -= arr[t]; // 回溯
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    Backtrack(1);

    cout << min_time;
}