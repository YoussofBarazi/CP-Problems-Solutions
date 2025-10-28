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

    vector<int> a(n);
    map<int, int> freq1, freq2;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        freq1[a[i]]++;
    }

    ll ans = 0, cnt = 0;

    for (auto x : a)
    {
        cnt += freq2[x] == 0;

        freq2[x]++;

        if (freq1[x] == freq2[x])
            ans += cnt;
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