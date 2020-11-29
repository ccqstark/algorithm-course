#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string num;
    int k;
    cin >> num >> k;

    while (k > 0)
    {
        for (int i = 0; i < num.size() - 1; i++)
        {
            if (num[i] > num[i + 1])
            {
                num.erase(i, 1);
                break;
            }
        }
        k--;

        while (num.size() > 1 && num[0] == '0')
            num.erase(0, 1);
    }

    cout << num;
}