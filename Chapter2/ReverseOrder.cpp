// 归并排序求逆序对
#include <iostream>
using namespace std;
void mergesort(int l,int r);
void getReverseOrder(int l,int r);

int arr[1001], temp[1001], ans=0;

int main(){

    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    getReverseOrder(0,n-1);
    cout<<ans;

}

// 归并，累加逆序
void mergesort(int l,int r){

    if (l>=r) return;
    int mid = (l+r)/2;
    int i = l, j = mid+1, k = 0;
    
    while(i<=mid && j<=r){

        if(arr[i]>arr[j]){
            temp[k++] = arr[j++];
            ans += mid-i+1;   // 右边的数对左边的每个数的逆序贡献
        }else {
            temp[k++] = arr[i++];
        }
        
    }

    while (i<=mid) temp[k++] += arr[i++];  // 把剩下的弄进temp中
    while (j<=r) temp[k++] = arr[j++];
    for (int i = 0; i < k; i++)
    {
        arr[l+i] = temp[i];     // 把temp更新到arr（原数组）中
    }

}

// 二分
void getReverseOrder(int l,int r){

    if(l>=r) return;
    int mid=(l+r)/2;
    getReverseOrder(l,mid);  // 左
    getReverseOrder(mid+1,r); // 右
    mergesort(l,r);
}
