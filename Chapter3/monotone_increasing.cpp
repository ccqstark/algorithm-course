// 单调递增最长子序列
#include <iostream>
using namespace std;
#define MAX 666
int arr[MAX];
int dp[MAX];
int n;

int longest_increasing(){

    // 初始化第一个
    dp[0] = 1;

    // 双重遍历
    for (int i = 0;i<n;i++){
        for (int j = 0;j<i;j++){
            // 利用子问题最优解
            if(arr[i]>arr[j]){
                dp[i] = (dp[j]+1>dp[i])?dp[j]+1:dp[i];
            }
        }
    }

    // 找出dp[]中最大的那个作为答案
    int max_len = 1;
    for (int i = 0;i<n;i++){
        max_len = (dp[i]>max_len)?dp[i]:max_len;
    }

    return max_len;
}




int main()
{
    cin>>n;
    for (int i = 0;i<n;i++){
        cin>>arr[i];
    }

    cout<<longest_increasing();
}