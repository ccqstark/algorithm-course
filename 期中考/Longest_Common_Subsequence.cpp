// 最长公共子序列 动态规划
#include <iostream>
#include <cstring>

using namespace std;
int dp[1003][1003] = {0};

int main()
{

    char s1[1002];
    char s2[1002];
    cin >> s1 >> s2;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // 初始化
    for (int i = 0; i < len1; i++)
    {
        if (s1[i] == s2[0])
        {
            while (i < len1)
            {
                dp[i][0] = 1;
                i++;
            }
            break;
        }
    }

    for (int i = 0; i < len2; i++)
    {
        if (s1[0] == s2[i])
        {
            while (i < len2)
            {
                dp[0][i] = 1;
                i++;
            }
            break;
        }
    }

    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] =dp[i - 1][j]>dp[i][j - 1]?dp[i - 1][j]:dp[i][j - 1];
            }
        }
    }

    
    int ans = dp[len1-1][len2-1]*100 / len1;
    if(ans > 75){
        cout<<ans<<"% Yes";
    }else{
        cout<<ans<<"% No";
    }

}