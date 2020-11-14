#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

bool compare(int a, int b){
    return a<b;
}

int main(){

    int n,arr[1002];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n,compare);

    float all_time = 0;
    
    float time[666];

    time[0] = 0;
    // 每个人的等待时间
    for (int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            time[i] += arr[j]; 
        }
    }

    for (int i=0;i<n;i++){
        all_time += time[i];
    }

    cout<<setiosflags(ios::fixed)<<setprecision(2)<<all_time/n<<endl;
}