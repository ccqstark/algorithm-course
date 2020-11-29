#include <iostream>
using namespace std;
int beeWay(int m, int n);

int main()
{

    int m, n;
    cin >> m >> n;
    cout << beeWay(m, n);
}

int beeWay(int m, int n)
{

    if ((n - m) == 1)
        return 1;
    if ((n - m) == 2)
        return 2;
    else
        return beeWay(m, n - 1) + beeWay(m, n - 2);
}