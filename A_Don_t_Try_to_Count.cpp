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

    string x, s;
    cin >> x >> s;

    int cnt = 0;
    bool ok = false;

    while (x.size() <= s.size() * 25)
    {
        if (x.find(s) != string::npos)
        {
            ok = true;
            break;
        }

        cnt++;
        x += x;
    }

    if (!ok)
        cnt = -1;

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