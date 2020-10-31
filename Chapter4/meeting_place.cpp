// 按开始时间排序
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 666

struct activity
{
    int start;
    int end;
    int arrage;
} activities[MAX];
int n;

bool struct_compare(activity a, activity b)
{
    if (a.start != b.start)
        return a.start < b.start; //优先进行最先开始的活动
    else
        return a.end < b.end; //当开始时间相同时,优先进行最早结束的活动
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> activities[i].start;
        cin >> activities[i].end;
        activities[i].arrage = 0;
    }
    // 初始化会场数
    int room = 0;

    // 对活动'开始时间'进行从小到大排序
    sort(activities, activities + n, struct_compare);

    // 记录当前安排会场的结束时间，被安排的会场数
    int lastest = 0, arrage_num = 0;

    // 如果会场还没有被全部安排完
    while (arrage_num != n)
    {
        // 新增一个会场
        room++;
        for (int i = 0; i < n; i++)
        {
            // 在一个会场中安排尽可能多的活动
            if (activities[i].arrage == 0 && activities[i].start >= lastest)
            {
                activities[i].arrage = 1; // 标记活动为已被安排
                arrage_num++;
                lastest = activities[i].end; // 更新当前会场的结束时间
            }
        }
        lastest = 0;
    }

    //另外一种写法，效果一样
    /*
    for (int i = 0; i < n; i++)
    {
        if (activities[i].arrage == 0)
        {
            room++;
            activities[i].arrage = 1;
            lastest = activities[i].end;
            for (int j = i + 1; j < n; j++)
            {
                if (activities[j].arrage == 0 && activities[j].start >= lastest)
                {
                    activities[j].arrage = 1;
                    lastest = activities[j].end;
                }
            }
        }
    }
    */

    cout << room;
    return 0;
}