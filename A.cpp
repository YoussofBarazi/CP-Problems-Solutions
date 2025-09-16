#include <bits/stdc++.h>

using namespace std;

const int N = 200009;

int main()
{
    long long x, y, m;
    cin >> x >> y >> m;

    long long ans = 1;

    for (long long i = 0 ; i < 31 ; i ++) {
        if (((1 << i) & y) > 0) {
            ans = (ans % m) * (x % m) % m;
        }

        x = ((x % m) * (x % m)) % m;
    }

    cout << ans << endl;
    return 0;
}
