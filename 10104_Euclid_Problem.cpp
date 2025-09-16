#include <iostream>
#include <cmath>

using namespace std;

int extendedEuclid(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    int x1, y1;
    int d = extendedEuclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

void solve(int a, int b)
{

    int x, y;
    int g = extendedEuclid(a, b, x, y);

    cout << x << " " << y << " " << g << endl;
}

int main()
{
    int a, b;

    while (cin >> a >> b)
    {
        solve(a, b);
    }

    return 0;
}