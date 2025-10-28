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
    ll n;
    cin >> n;

    vector<ll> a(n - 1);
    map<ll, ll> s;

    for (auto &x : a)
    {
        cin >> x;
    }

    bool ok = true;
    if (a.back() > (1 + n) * n / 2)
    {
        ok = false;
    }

    if (a.back() < (1 + n) * n / 2)
        s[(1 + n) * n / 2 - a.back()]++;

    s[a[0]]++;

    for (int i = 1; i < n - 1; i++)
    {
        s[a[i] - a[i - 1]]++;
    }

    int cnt = 0;
    ll sum = 0;

    for (int i = 1; i <= n; i++)
        if (s.find(i) == s.end())
        {
            cnt++, sum += i;
            s[i]++;
        }

    if (cnt == 2)
    {
        s[sum]--;

        if (s[sum] < 0)
            ok = false;
        if (s[sum] <= 0)
            s.erase(sum);
    }

    for (auto x : s)
    {
        if (x.S > 1 || x.F > n)
        {
            ok = false;
            break;
        }
    }

    if (!ok || cnt > 2 || s.size() != n)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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