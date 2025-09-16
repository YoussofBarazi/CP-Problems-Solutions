#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define s first
#define e second
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

    vector<pair<int, int>> a(n);
    vector<int> x(1009, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].s >> a[i].e;
        x[a[i].s]++, x[a[i].e]--;
    }

    for (int i = 1; i < 1009; i++)
        x[i] += x[i - 1];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int covered = 0;

        for (int j = a[i].s; j < a[i].e; j++)
            x[j]--;

        for (int i = 0; i < 1009; i++)
            covered += x[i] > 0;

        for (int j = a[i].s; j < a[i].e; j++)
            x[j]++;

        ans = max(ans, covered);
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