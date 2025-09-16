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

vector<int> mx_div(1e6 + 1, 0);

void get()
{
    for (size_t i = 2; i <= 1e6; i++)
    {
        if (mx_div[i] == 0)
            for (size_t j = i; j <= 1e6; j += i)
            {
                mx_div[j] = i;
            }
    }
}

void solve()
{
    int n;
    cin >> n;

    int ans = 1;
    while (n > 1)
    {
        int x = mx_div[n], cnt = 0;

        while (n % x == 0)
        {
            n /= x;
            cnt++;
        }

        ans *= (cnt + 1);
    }

    cout << ans << endl;
}

int main()
{
    IOS;
    get();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}