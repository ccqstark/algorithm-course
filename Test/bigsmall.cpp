#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char str[31];
    cin.getline(str, 30);

    for (int i = 0; i < strlen(str); i++)
    {

        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
        else if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    }

    for (int i = 0; i < strlen(str)-1; i++)
    {
        cout << str[i];     
    }
    
}