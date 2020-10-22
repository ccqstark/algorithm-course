// 动态规划版————最大子段和
#include <iostream>
using namespace std;
int n;
#define MAX 666
int arr[MAX]={0};

int MaxSum();

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<<MaxSum();
}

int MaxSum()
{

    int sum = 0, b = 0;

    for (int i = 0; i < n; i++)
    {
        if (b > 0)
        {
            b += arr[i]; // 字段扩充
        }
        else
        {
            b = arr[i]; // 连续和小于0，换起始点为当前点重新开始
        }

        if (b > sum)
        {
            sum = b;    // 更新最大子段和
        }
    }

    return sum;
}