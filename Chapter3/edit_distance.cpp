// 编辑距离问题
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 2002
char A[MAX];
char B[MAX];
int dp[MAX][MAX];

int calculate_distance()
{

    // a、b字符串的长度
    int len_a = strlen(A);
    int len_b = strlen(B);

    // 边界初始化
    for (int i = 0; i <= len_a; i++)
        dp[i][0] = i;
    for (int j = 0; j <= len_b; j++)
        dp[0][j] = j;

    for (int i = 1; i <= len_a; i++)
    {
        for (int j = 1; j <= len_b; j++)
        {
            // dp矩阵以1开始，字符数组是0开始，因此对应的话要-1
            if (A[i - 1] == B[j - 1])
                // 如果对应的位置相同就不用操作，否则要修改所以要+1
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;

            //              修改              删除              插入
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
    }

    return dp[len_a][len_b];
}

int main()
{
    cin >> A >> B;

    cout << calculate_distance();
}