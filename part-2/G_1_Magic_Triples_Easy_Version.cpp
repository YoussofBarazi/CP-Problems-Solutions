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
    int n;
    cin >> n;

    map<int, ll> freq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        freq[x]++;
    }

    ll ans = 0;

    for (auto x : freq)
    {
        int num = x.F;

        if (freq[num] >= 3)
        {
            ans += freq[num] * (freq[num] - 1) * (freq[num] - 2);
        }

        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0 && num % (i * i) == 0)
            {
                ans += freq[num] * freq[num / i] * freq[num / (i * i)];
            }
        }
    }

    cout << ans << endl;
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