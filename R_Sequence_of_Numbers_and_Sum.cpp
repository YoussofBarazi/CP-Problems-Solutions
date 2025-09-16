#include <iostream>

using namespace std;

int main()
{
    int a, b;

    while (cin >> a >> b && a > 0 && b > 0)
    {
        int sum = 0;
        if (a >= b)
        {
            for (int i = b; i <= a; i++)
            {
                cout << i << " ";
                sum += i;
            }

            cout << "sum =" << sum << endl;
        }
        else
        {
            for (int i = a; i <= b; i++)
            {
                cout << i << " ";
                sum += i;
            }
         
            cout << "sum =" << sum << endl;
        }
    }
}