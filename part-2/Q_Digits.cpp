#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (x == 0)
            cout << 0;
        else
        {
            while (x)
            {
                int temp = x % 10;
                cout << temp << " ";
                x /= 10;
            }
        }
        cout << endl;
    }

    return 0;
}