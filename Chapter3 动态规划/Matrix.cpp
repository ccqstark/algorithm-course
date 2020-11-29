// 矩阵链相乘问题
#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 1000;
int p[MAX];      // 存放行列数，就是题目输入的序列
int m[MAX][MAX]; // 存放局部和最终结果的矩阵
int n;           // 需要相乘的矩阵个数

void matrix()
{
    memset(m, 0, sizeof(m)); // 初始化矩阵为0

    // 同时连续相乘的个数
    for (int r = 2; r <= n; r++)
    {
        // 从第几个开始(到第几组了)
        for (int i = 1; i <= n - r + 1; i++)
        {
            // 相乘链的最后一个
            int j = i + r - 1;

            // 为了通过比较从而得出最小的那个，要有一个比较的初值，这里是划分第一个和其余的为2组
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];

            // 一步步移动划分点
            for (int k = i + 1; k < j; k++)
            {
                // 以k位置为划分点，划分i到j的相乘链
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                // 比较找出最小的那个
                if (t < m[i][j])
                {
                    m[i][j] = t;
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    // 输入的数字总数比矩阵个数多1
    for (int i = 0; i < n + 1; i++)
    {
        cin >> p[i];
    }
    matrix();

    // 最后答案会在右上角出现
    cout << m[1][n];
}