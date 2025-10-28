// not complete
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
    int n, m;
    cin >> n >> m;

    map<int, ll> freq;
    map<int, int> hasPair;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        a[i] %= m;
        freq[a[i]]++;
    }

    sort(allrev(a));
    int size = unique(all(a)) - a.begin();

    ll allPairs = 0;
    for (int i = 0; i < size; i++)
    {
        allPairs += freq[a[i]] * freq[m - a[i]];
        if (freq[a[i] - m] > 0)
            hasPair[a[i]] = m - a[i], hasPair[m - a[i]] = a[i];
    }
    cout << allPairs << endl;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (hasPair[x] > 0)
        {
            allPairs -= freq[hasPair[x]];
            if (freq[x] > 0)
                freq[x]--;
        }

        ll r = n - i;
        if (i == n || allPairs == r * (r - 1) / 2)
        {
            if (n == i)
                i = 1;

            cout << i << endl;
            return;
        }
    }
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}