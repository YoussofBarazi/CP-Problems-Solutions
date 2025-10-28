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

vector<int> b;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    b.clear();
    b.pb(-1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
            b.pb(i);
    }
    b.pb(n);

    int ans = 0;
    for (int i = 1; i < b.size() - 1; i++)
    {
        ans += b[i] - b[i - 1] - 1;
    }

    if (b.size() > 2 && b[b.size() - 1] - b[b.size() - 2] - 1 > b[b.size() - 2] - b[b.size() - 3] - 1)
        ans -= b[b.size() - 2] - b[b.size() - 3] - 1, ans += b[b.size() - 1] - b[b.size() - 2] - 1;

    int t = 0;

    for (int i = 1; i < b.size() - 1; i++)
    {
        t += b[i + 1] - b[i] - 1;
    }

    cout << max(ans, t) << endl;
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