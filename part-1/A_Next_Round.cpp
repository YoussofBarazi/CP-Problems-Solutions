#include <iostream>
#include <string>
using namespace std;

const int N = 50 + 5;

int a[N];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= a[k - 1] && a[i] > 0)
            c++;
    }

    cout << c;

    return 0;
}