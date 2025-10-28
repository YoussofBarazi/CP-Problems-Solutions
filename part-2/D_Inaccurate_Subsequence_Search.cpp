#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    map<int, int> b, c;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        b[x]++;
    }

    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        if (b.count(a[i]))
        {
            c[a[i]]++;
        }
    }

    for (auto x : b)
    {
        cnt += min(c[x.F] , x.S);
    }

    int ans = (cnt >= k);

    for (int i = m; i < n; i++)
    {
        if (b.count(a[i - m]))
        {
            if (c[a[i - m]] <= b[a[i - m]])
                cnt --;
            c[a[i - m]]--;
        }
        if (b.count(a[i]))
        {
            c[a[i]]++;
            if (c[a[i]] <= b[a[i]])
                cnt ++;
        }
        ans += (cnt >= k);
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}