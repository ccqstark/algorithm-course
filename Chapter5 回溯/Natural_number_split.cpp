// 自然数的拆分
#include <iostream>
using namespace std;
int n; // 被拆分目标数
#define MAX 22
int num[MAX];
int g; // 当前和

// 输出函数
void output(int t)
{
    cout << n << "=" << num[1];
    for (int i = 2; i <= t; i++)
    {
        cout << "+" << num[i];
    }
    cout << endl;
}

void Backtrack(int t)
{
    // 当前和达到n，输出
    if (g == n)
    {
        output(t - 1);
        return;
    }

    // 要小于n，不能输出n=n
    for (int i = 1; i < n; i++)
    {
        num[t] = i;
        g += num[t];
        // 剪枝，和不能大于目标数，且后一个加数不能比上一个大
        if (g <= n && num[t] >= num[t - 1])
        {
            Backtrack(t + 1);
        }
        g -= num[t]; // 回溯
    }
}

int main()
{
    cin >> n;

    Backtrack(1);
}