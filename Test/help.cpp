#include <iostream>
#include <algorithm>
using namespace std;

struct ans
{
    int num;
    char name[30];
    int score[3];
} anss[666];

void print()
{
    for (int i = 0; i < 5; i++)
    {
        cout << anss[i].num << " ";
        cout << anss[i].name << " ";
        cout << anss[i].score[0] << " ";
        cout << anss[i].score[1] << " ";
        cout << anss[i].score[2] << endl;
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> anss[i].num;
        cin >> anss[i].name;
        cin >> anss[i].score[0];
        cin >> anss[i].score[1];
        cin >> anss[i].score[2];
    }
    print();
}