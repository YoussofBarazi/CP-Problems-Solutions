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
    map<int, ll> freq;

    for (int &x : a)
    {
        cin >> x;

        freq[x]++;
    }
    sort(allrev(a));
    set<vector<int>> tubles;
    ll ans = 0;
    for (int i : a)
    {
        if (tubles.find({i, i, i}) == tubles.end())
        {
            ans += (freq[i] - 1) * (freq[i] - 2) * freq[i] / 6;
            tubles.insert({i, i, i});
        }

        if (tubles.find({i, i, i - 1}) == tubles.end())
        {
            ans += ((freq[i] - 1) * freq[i] / 2) * freq[i - 1];
            tubles.insert({i, i, i - 1});
        }

        if (tubles.find({i, i - 1, i - 1}) == tubles.end())
        {
            ans += freq[i] * (freq[i - 1] * (freq[i - 1] - 1)) / 2;
            tubles.insert({i, i - 1, i - 1});
        }

        if (tubles.find({i, i, i - 2}) == tubles.end())
        {
            ans += ((freq[i] - 1) * freq[i] / 2) * freq[i - 2];
            tubles.insert({i, i, i - 2});
        }

        if (tubles.find({i, i - 2, i - 2}) == tubles.end())
        {
            ans += freq[i] * freq[i - 2] * (freq[i - 2] - 1) / 2;
            tubles.insert({i, i - 2, i - 2});
        }

        if (tubles.find({i, i - 1, i - 2}) == tubles.end())
        {
            ans += freq[i] * freq[i - 1] * freq[i - 2];
            tubles.insert({i, i - 1, i - 2});
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