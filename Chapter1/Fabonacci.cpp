#include <iostream>
using namespace std;

int arr[1000002]={0};

int main(){

    long long int n;
    cin>>n;

    if (n==1||n==2)
    {
       cout<<1;
       return 0;
    }

    arr[1] = 1;

    for (int i = 2; i <= n ; i++)
    {
        arr[i] = arr[i-1]%10 + arr[i-2]%10;
    }

    cout<<arr[n]%10;
}
