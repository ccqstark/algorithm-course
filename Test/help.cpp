#include <iostream>
#include <algorithm>
using namespace std;

struct ans
{
    int value;
    int h;
    int l;
} anss[666];

bool compare(ans a, ans b){

    if (a.h != b.h)
        return a.h<b.h;
    else
        return a.l<b.l;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int arr[666][666];
    for(int i=1;i<=m;i++){
       for(int j=1;j<=n;j++){
           cin>>arr[i][j];
       }
    }

    int num = 0;

    for(int i=2;i<=m-1;i++){
       for(int j=2;j<=n-1;j++){
           if(arr[i][j]>arr[i-1][j] && arr[i][j]>arr[i][j-1] && arr[i][j]>arr[i+1][j] && arr[i][j]>arr[i][j+1]){
               num++;
               anss[num].value = arr[i][j];
               anss[num].h = i;
               anss[num].l = j; 
           }
       }
    }

    if(num!=0){
        sort(anss+1,anss+num+1,compare);
         for(int i=1;i<=num;i++){
             cout<<anss[i].value<<" "<<anss[i].h<<" "<<anss[i].l<<endl;
         }
    }else{
        cout<<"None "<<m<<" "<<n;
    }
}