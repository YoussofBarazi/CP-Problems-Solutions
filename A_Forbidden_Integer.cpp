#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;

    string ans = "";

    if (k == 1 && x == 1)
        ans = "NO";
    else if (n == 2 && x == 1 && k == 1)
        ans = "NO";
    else if (x == 1 && k < 3 && n % 2)
        ans = "NO";
    else
        ans = "YES";

    cout << ans << endl;

    if (ans == "YES")
    {
        if (x != 1)
        {
            cout << n << endl;
            for (int i = 0; i < n; i++)
                cout << 1 << " ";
            cout << endl;
        }
        else
        {
            cout << n / 2 << endl;
            if (n % 2)
            {
                cout << 3 << " ";
                n -= 3;
            }

            while (n > 0)
            {
                cout << 2 << " ";
                n -= 2;
            }

            cout << endl;
        }
    }
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}