#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    int ans = 0, sum = 0;

    for (int i = 0; i < 3; i++)
    {
        cin >> a;

        ans += a, sum += a;
        if (sum >= 500)
            ans -= 100, sum = 0;
    }

    cout << ans << endl;

    return 0;
}