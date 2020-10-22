#include <iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    if(m>n || m<100 || n>999){
        cout << "Invalid value"<<endl;
        return 0;
    }

    for (int i = m; i <= n; i++)
    {
        int a =  i/100;
        int b = (i - a * 100)/10;
        int c = i - a*100 - b*10;
        if ((a*a*a + b*b*b + c*c*c)==i){
            cout<<i<<endl;
        }
    }

}