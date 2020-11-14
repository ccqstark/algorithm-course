#include <iostream>
#include <algorithm>
using namespace std;

struct interval
{
    int a;
    int b;
} intervals[666];

bool compare(interval j, interval k)
{

    if (j.a != k.a)
    {
        return j.b < k.b;
    }
    else
    {
        return j.a > k.a;
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i].a >> intervals[i].b;
    }

    sort(intervals, intervals + n, compare);

    int done = 0, ans = 0;
    while (done != n)
    {
        ans++;
        int p = intervals[done].b;

        while (1)
        {
            if (p >= intervals[done + 1].a && p <= intervals[done + 1].b)
                done++;
            else
                break;
        }
        done++;
    }


    cout << ans;
}