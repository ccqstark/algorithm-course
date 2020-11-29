#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a <= b;
}

int main()
{
    int n;
    cin >> n;
    int arr[102];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, compare);

    int time = 600;
    int ans = n;

    for (int i = 0; i < n; i++)
    {
        if (time-arr[i] >= 0)
        {
            time -= arr[i];
            ans--;
        }
        else
            break;
    }

    cout << ans;
}