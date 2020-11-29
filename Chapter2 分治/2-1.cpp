#include <iostream>
using namespace std;
int bin_search(int *arr, int left, int right, int x);

int main()
{

    int n, x;
    cin >> n >> x;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int index = bin_search(arr, 0, n-1, x);
    cout << index;

    return 0;
}

int bin_search(int *arr, int left, int right, int x)
{
    int mid = (left + right) / 2;
    if (x == arr[mid]) {
        return mid;
    }
        
        
    else if (left > right)
        return -1;

    else if (x < arr[mid])
        bin_search(arr, left, mid - 1, x);
    else if (x > arr[mid])
        bin_search(arr, mid + 1, right, x);
}