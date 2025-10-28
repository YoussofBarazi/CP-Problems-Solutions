#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 1000009;

int a, b, l, g;

bool check(int x)
{
    if (x % b && x % a)
        return false;

    int cnt = 0;

    while (a > 1 && x % a == 0)
    {
        cnt++;
        x /= a;
    }

    if (x == 1)
        return true;

    while (cnt > 0 && x % b)
    {
        x *= a;
        cnt--;
    }

    while (b > 1 && x % b == 0)
    {
        x /= b;

        if (x == 1)
            return true;

        while (cnt > 0 && x % b)
        {
            x *= a;
            cnt--;
        }
    }

    return (x == 1);
}

void solve()
{
    cin >> a >> b >> l;

    int ans = 1;

    for (int i = 1; i * i <= l; i++)
    {
        if (l % i == 0)
        {
            ans += check(i);

            if (i * i != l)
            {
                ans += check(l / i);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}