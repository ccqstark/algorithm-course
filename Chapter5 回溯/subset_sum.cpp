// 子集和问题
#include <iostream>
#define MAX 6666
using namespace std;
int sum = 0, n, c;
int arr[MAX];
int ans[MAX]; // 是否选择的标志
int flag = 0; // 是否已经找到解的标志

void print_ans()
{
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 1)
            cout << arr[i] << " ";
    }
}

void Backtrack(int t)
{
    // 保证是第一个解
    if (sum == c && flag == 0)
    {
        flag = 1;
        print_ans();
        return;
    }
    // 到叶子节点，同时剪枝
    if (t > n || flag == 1)
        return;

    ans[t] = 1; // 选择此数
    sum += arr[t];
    // 剪枝
    if (sum <= c)
    {
        Backtrack(t + 1);
    }
    sum -= arr[t]; // 剪枝

    ans[t] = 0; // 不选此数
    if (sum <= c)
    {
        Backtrack(t + 1);
    }

    return;
}

int main()
{

    cin >> n >> c;
    int sum_pre = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum_pre += arr[i];
    }

    // 优化，缩短时间
    if (sum_pre < c)
        cout << "No Solution!";
    else
    {
        Backtrack(1);

        if (!flag)
            cout << "No Solution!";
    }
}