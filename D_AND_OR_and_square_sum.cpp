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

    vector<int> freq(21, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        for (int i = 0; i < 20; i++)
        {
            freq[i] += bool(x & (1 << i));
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll s = 0;
        for (int i = 0; i < 20; i++)
        {
            if (freq[i] > 0)
            {
                s += 1 << i;
                freq[i]--;
            }
        }

        ans += s * s;
    }

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