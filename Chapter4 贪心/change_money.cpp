// 找零问题
#include <iostream>
using namespace std;
int face_value[7] = {100, 50, 20, 10, 5, 2, 1}; // 面值
int num[7] = {0};

int main()
{

    int m, n;
    cin >> m >> n;
    m -= n;

    while (m != 0)
    {
        // 选取可以找零的最大面值，使得纸币数量最少
        for (int i = 0; i < 7; i++)
        {
            if (m >= face_value[i])
            {
                m -= face_value[i];
                num[i]++;
                break;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        if (num[i] != 0)
        {
            cout << face_value[i] << " " << num[i] << endl;
        }
    }
}