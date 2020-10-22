// 最低通行费
#include <iostream>
using namespace std;
int n;
#define MAX 102
int matrix[MAX][MAX];
int p[MAX][MAX];
	
int lowest_cost(){
    // 初始化起点
	p[0][0] = matrix[0][0];

    // 遍历填表
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
            // 第0行或第0列，只考虑左边或上边
			if(i==0) p[i][j] = p[i][j-1] + matrix[i][j];
			else if (j == 0) p[i][j] = p[i-1][j] + matrix[i][j];

			else{
                // 选择上方或左方中较小的那个
				int mini = (p[i][j-1]<p[i-1][j])?p[i][j-1]:p[i-1][j];
				p[i][j] = mini+matrix[i][j];
			} 
		
		}
	}
	
    // 答案在右下角
	return p[n-1][n-1];
}	
	
	

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}
	}
	
	
	cout<<lowest_cost();
	
} 