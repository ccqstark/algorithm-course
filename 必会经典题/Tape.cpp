#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 666
int n, L;
int arr[MAX];

int main()
{

    cin >> n >> L;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (L - arr[i] >= 0)
        {
            L -= arr[i];
            ans++;
        }
        else
            break;
    }
    cout << ans;
}