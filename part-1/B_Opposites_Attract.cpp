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

void solve()
{
    int n;
    cin >> n;

    vector<ll> neg(11, 0), pos(11, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x >= 0)
            pos[x]++;
        else
            neg[-x]++;
    }

    ll ans = 0;
    for (int i = 1; i < 11; i++)
        ans += pos[i] * neg[i];

    ans += pos[0] * (pos[0] - 1) / 2;

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