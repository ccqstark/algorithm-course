#include<iostream>
using namespace std;

int func(int arr[],int left, int right,int all){
    int mid = (left + right)/2;

    if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]) return arr[mid];
    
    else if(arr[mid]<arr[mid+1] && mid+1 == all) return arr[mid+1];
    
    else if(arr[mid]>arr[mid-1]) return func(arr,mid,right,all);
    
    else if(arr[mid]<arr[mid-1]) return func(arr,left,mid,all);
}


int main() 
{
    int n;
    cin>>n;
    int arr[666];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    cout<<func(arr,0,n-1,n-1); 
}