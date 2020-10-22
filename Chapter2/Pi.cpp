// 分派，二分法求每个人能分到的最大派的体积
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
double pi = acos(-1.0); // -1的反余弦是pi
int n,f;
double cake[10001]; // 存放每块蛋糕的体积
double r [10001];  // 每块蛋糕的半径
bool isCan(double itsSize); // 判断当前的分法是否够这么多人分

int main(){

    
    cin>>n>>f;
    f++; // 算上自己

  
    double max=0;
    for (int i = 0; i < n; i++)
    {
        cin>>r[i];
        cake[i] = pi * r[i] * r[i];

        if(cake[i]>max) max = cake[i]; // 找出最大的那个
    }
    

    double left=0,right=max;
    double mid;
    while ((right-left)>1e-5){ // 1e-5作为判断两数基本相等的界限

        mid = (left+right)/2; // 二分
        if (!isCan(mid)) { // 判断是否够分
            right = mid;
        }else{
            left = mid;
        }
    }

    printf("%.3f",mid);    

}

bool isCan(double itsSize)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += int(cake[i]/itsSize);
    }
    
    if (sum>=f) return true;  // 通过算一共可以分为几份来判断够不够分
    else return false;

}