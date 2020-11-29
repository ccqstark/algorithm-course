#include <iostream>
#include <string>
using namespace std;
string dict[100002];
string words[100002];

bool bin_search(int left, int right, string x)
{
    int mid = (left + right) / 2;
    if(left > right)
        return false;

    else if (x == dict[mid])
        return true;
    else if (x < dict[mid])
        return bin_search(left, mid - 1, x);
    else if (x > dict[mid])
        return bin_search(mid + 1, right, x);
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> words[i];
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (!bin_search(0, n-1, words[i]))
            ans++;
    }

    cout<<ans;
}
