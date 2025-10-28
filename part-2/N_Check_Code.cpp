#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool result = true;
    for (int i = 0; i < a + b; i++)
    {
        if (i == a)
        {
            if (s[i] != '-')
                result = false;
        }
        else 
        {
            if (s[i] < '0' || s[i] > '9')
            {
                result = false;
            }
        }
    }

    if (result == true)
        cout << "Yes";
    else
        cout << "No";
}