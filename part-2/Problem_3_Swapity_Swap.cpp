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

const int N = 209;

void solve()
{
    int n, k;
    cin >> n >> k;

    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    a1--, a2--, b1--, b2--;

    vector<int> p(n);
    iota(all(p), 1);

    int cnt = 0;
    while (cnt < min(k, 10000000))
    {
        for (int i = a1, j = a2; i < j; i++, j--)
            swap(p[i], p[j]);
        for (int i = b1, j = b2; i < j; i++, j--)
            swap(p[i], p[j]);

        cnt++;
    }

    for (auto x : p)
        cout << x << endl;
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