// 游艇租用问题
#include <iostream>
using namespace std;

#define MAX 666
int arr[MAX][MAX];
int re[MAX][MAX];
int n;
int rent_yacht();

int main(){

    cin>>n;
    for (int i=1;i<=n-1;i++){
        for (int j=i+1;j<=n;j++){
            cin>>arr[i][j];
        }
    }

    cout<<rent_yacht();

}

int rent_yacht(){

    // 相邻2个站之间的费用只有一种可能
    for (int i = 1; i <= n-1; i++)
    {
        re[i][i+1] = arr[i][i+1];
    }
    

    // 跨度递增
    for(int i=2;i<=n-1;i++){
        // 起始点递增
        for (int j=1;j+i<=n;j++)
        {
            // 用于比较的初值
            re[j][j+i] = re[j][j+1] + re[j+1][j+i];
            // 切分点递增
            for (int k=j+1;k<=j+i-1;k++){

                // 要和原来数组的值算出来的结果也比较一下谁小
                int temp1 = re[j][k] + re[k][j+i];
                int temp2 = arr[j][k] + arr[k][j+i];
                int temp = (temp1<temp2)?temp1:temp2; // 找最小

                if (temp<re[j][j+i]){
                    re[j][j+i] = temp;
                } 
            }
        }
    }

    // 问题要求的就是从站点1到站点n
    return re[1][n];
}
