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
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++)
        cin >> a[i];

    a[0] = 1;

    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(all(a)), sort(all(b));

    int j = 0, i = 0, cnt = 0;
    for (; i < n; i++)
    {
        while (j < n && a[i] >= b[j])
        {
            j++;
            cnt++;
        }

        j++;

        if (j >= n)
        {
            break;
        }
    }

    cout << cnt << endl;
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