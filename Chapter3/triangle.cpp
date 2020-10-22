// 数字三角形问题（最长最短路径）
#include <iostream>
using namespace std;

#define MAX 666
int arr[MAX][MAX];
int n;
int solve_triangle();

int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<solve_triangle();
}

int solve_triangle()
{
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            // 从倒数第二行开始，每一行把对应下面的2个子数中较大或小的与自己相加，层层上去，最后arr[1][1]位置的数就是答案
            int addnum = (arr[i + 1][j] < arr[i + 1][j + 1]) ? arr[i + 1][j] : arr[i + 1][j + 1];
            arr[i][j] += addnum;
        }
    }

    return arr[1][1];
}