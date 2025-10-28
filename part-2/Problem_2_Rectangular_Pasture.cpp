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

bool cmp(const pi &p1, const pi &p2)
{
    return p1.S < p2.S;
}

void solve()
{
    int n;
    cin >> n;

    vector<pi> a(n);
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        a[i] = {x, y};
    }

    sort(all(a));
    for (size_t i = 0; i < n; i++)
    {
        a[i].F = i;
    }

    sort(all(a), cmp);
    for (size_t i = 0; i < n; i++)
    {
        a[i].S = i;
    }

    sort(all(a));
    vector<vi> lower(n, vi(n + 1)), greater(n, vi(n + 1));

    for (size_t i = 0; i < n; i++)
    {
        int y = a[i].S;
        for (size_t x = 1; x <= n; x++)
        {
            lower[y][x] = lower[y][x - 1];
            if (a[x - 1].S < y)
                lower[y][x]++;
            greater[y][x] = greater[y][x - 1];
            if (a[x - 1].S > y)
                greater[y][x]++;
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            cout << greater[y][x] << "," << lower[y][x] << " ";
        cout << endl;
    }

    ll total = n + 1;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            int low = min(a[j].S, a[i].S);
            int high = max(a[j].S, a[i].S);

            ll low_ans = 1 + lower[low][j + 1] - lower[low][i];
            ll high_ans = 1 + greater[high][j + 1] - greater[high][i];

            total += low_ans * high_ans;
        }
    }

    cout << total << endl;
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