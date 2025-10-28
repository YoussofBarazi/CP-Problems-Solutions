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

    map<vector<int>, int> freq;
    vector<string> s(n);

    ll ans = 0;

    for (auto &x : s)
    {
        cin >> x;

        vector<int> mask(26, 0);

        for (auto c : x)
        {
            mask[c - 'a']++;
            mask[c - 'a'] %= 2;
        }

        int &cnt = freq[mask];

        ans += cnt;

        cnt++;
    }

    for (auto x : freq)
    {
        vector<int> mask = x.F;
        for (int &w : mask)
        {
            if (w)
            {
                w = 0;
                if (freq.count(mask))
                    ans += freq[mask] * x.S;
                w = 1;
            }
        }
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