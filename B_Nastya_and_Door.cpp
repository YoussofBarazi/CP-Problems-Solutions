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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n , k;
    cin >> n >> k;

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    deque <int> peaks;
    for (size_t i = 1; i < k - 1; i++)
    {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
        {
            peaks.push_back(a[i]);
        }
    }

    int l = 0;
    int mx = peaks.size();

    for (size_t i = 1; i + k - 1 < n; i++)
    {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
        {
            peaks.pop_front();
        }
        if (a[i + k - 3] < a[i + k - 2] && a[i + k - 2] > a[i + k - 1])
        {
            peaks.push_back(a[i]);
        }
        if (peaks.size() > mx)
        {
            l = i;
            mx = peaks.size();
        }
    }
    cout << mx + 1 << " " << l + 1 << endl;
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