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

const int N = 200009;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &x : a)
        cin >> x;

    int cnt = 0; // الأصفار يلي مجبر عليها

    bool ok = a[0] <= 0;

    // if (a[0] == -1)
    a[0] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int c = 0;

        if (a[i] >= 0)
        {
            // 0 , 0 , 1 , 2
            // 0 , 1 , 2 , 3

            for (int j = i - a[i]; j <= i; j++)
            {
                if (a[j] != c && a[j] != -1)
                {
                    ok = false;
                    break;
                }

                // if (a[j] == -1)
                a[j] = c;

                c++;
            }
        }

        cnt += a[i] == 0;
    }

    if (!ok)
    {
        cout << -1 << endl;
        return;
    }

    int mn = cnt, mx = cnt;

    for (int i = 0; i < n; i++)
        mx += a[i] == -1;

    cout << mn << " " << mx << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

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