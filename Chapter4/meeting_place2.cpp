//按结束时间排序
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 666

struct activity
{
    int start;
    int end;
} activities[MAX];
int n;
int end_time[MAX] = {0}; // 记录每个会场的结束时间
int room = 1;            // 会场数

bool struct_compare(activity a, activity b)
{
    if (a.end != b.end)
        return a.end < b.end; //优先进行最早结束的活动

    else
        return a.start < b.start; //当结束时间相同时,优先进行最早开始的活动
}

bool dcmp(int a, int b)
{
    return a > b; // 从大到小排序
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> activities[i].start;
        cin >> activities[i].end;
    }

    // 对活动按'结束时间'进行排序
    sort(activities, activities + n, struct_compare);

    // 遍历活动
    for (int i = 0; i < n; i++)
    {
        int flag = 0;                   // 标记是否在已开辟的会场中被安排
        for (int j = 1; j <= room; j++) // 遍历已有会场寻找合适的
        {
            if (activities[i].start >= end_time[j])
            {
                end_time[j] = activities[i].end;
                flag = 1;
                break;
            }
        }

        // 已有会场找不到合适的就开辟一个新的
        if (!flag)
        {
            room++;
            end_time[room] = activities[i].end;
        }

        // 每次安排完一个活动都要对会场们按结束时间从大到小重排
        sort(end_time + 1, end_time + room + 1, dcmp);
    }

    cout << room;
    return 0;
}