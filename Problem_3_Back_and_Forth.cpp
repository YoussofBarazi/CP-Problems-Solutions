#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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

int a[10], b[10];
bool taken1[10], taken2[10];
bool unique_reading[10009];

void O_O(int x = 1, int r = 1000)
{
    if (x == 5)
    {
        unique_reading[r] = true;
        return;
    }

    if (x % 2)
    {
        for (int i = 0; i < 10; i++)
        {
            if (!taken1[i])
            {
                taken1[i] = true;
                O_O(x + 1, r - a[i]);
                taken1[i] = false;
            }
            if (taken2[i])
            {
                taken2[i] = false;
                O_O(x + 1, r - b[i]);
                taken2[i] = true;
            }
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (!taken2[i])
            {
                taken2[i] = true;
                O_O(x + 1, r + b[i]);
                taken2[i] = false;
            }
            if (taken1[i])
            {
                taken1[i] = false;
                O_O(x + 1, r + a[i]);
                taken1[i] = true;
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    for (int i = 0; i < 10; i++)
        cin >> b[i];

    O_O();

    int ans = 0;
    for (int i = 0; i < 10001; i++)
        ans += unique_reading[i];

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}