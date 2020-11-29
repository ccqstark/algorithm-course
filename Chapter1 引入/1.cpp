#include <iostream>
using namespace std;


int main(){

    int num, max, index=0;
    cin>>num;
    int *arr = new int[num];
  
    for (int i = 0; i < num; i++)
    {
        cin>>arr[i];
    }
    
    max = arr[0];

    for (int i = 1; i < num; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
            index = i;
        }    
    }

    cout<<max<<" "<<index;
    
    return 0;
}