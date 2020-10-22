/*  
	分治法求最大序列和
	二分，算mid左边的最大序列，再算mid右边的最大序列
	两者相加作为这个mid的最大子序列，在和此mid的左mid和右mid的最大子序列比较
	最后那个最大的就是答案
	题目还是分治：二分+递归
*/
#include<iostream>
using namespace std;
int MaxSub(int *arr,int left, int right);

int main(){
	 
	int n;
	cin>>n;
	
	int arr[100001];
	for (int i = 0;i<n;i++){
		cin>>arr[i];
	}


	cout<<MaxSub(arr,0,n-1);
}

int MaxSub(int arr[],int left, int right){
	
	int mid = (left + right)/2;
	
	
	if(left==right){
        if(arr[left]>0) return arr[left];
        else return 0;       
	}
	
	
	
	int max1 = 0;
	int sum = 0;
	for (int i = mid+1;i<=right;i++){
		sum+=arr[i];
		if(max1<sum) max1 = sum;
	}
	
	int max2 = 0;
	sum = 0;
	for (int i = mid;i>=left;i--){
		sum+=arr[i];
		if(max2<sum) max2 = sum;
	}
	
	int max_mid = max1+ max2;

	
	
	int max_left = MaxSub(arr,left,mid);
	int max_right = MaxSub(arr,mid+1,right);
	

	
	int max = 0;
	
	if (max_left>max_mid) {
		max = max_left;	
	}else{
		max = max_mid;
	}
	
	if (max<max_right){
		max = max_right;
	}
	
	return max;
}

 