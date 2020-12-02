#include <iostream>
using namespace std;
#define MAX 110002
int n;
int arr[MAX];

bool bin_search(int left, int right, int x)
{
    if (left > right)
        return false;

    int mid = (left + right) / 2;

    if (arr[mid] == x)
        return true;
    else if (x < arr[mid])
        return bin_search(left, mid - 1, x);
    else if (x > arr[mid])
        return bin_search(mid + 1, right, x);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int num[MAX];
    int index = 0;
    while (1)
    {
        cin >> num[index];
        if (num[index] == 0)
            break;
        index++;
    }

    for (int i = 0; i < index; i++)
    {
        if (bin_search(0, n, num[i]))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}