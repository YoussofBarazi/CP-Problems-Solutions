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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cntW = 0;
    for (size_t i = 0; i < n; i++)
    {
        cntW += (s[i] == 'W');
    }
    if (cntW % 2 && n % 2 == 0)
    {
        cout << -1 << endl;
        return;
    }

    vi ans1, ans2;
    for (size_t i = 1; i < n; i++)
    {
        if (s[i - 1] == 'B')
        {
            s[i - 1] = 'W';
            s[i] = (s[i] == 'W') ? 'B' : 'W';

            ans1.pb(i);
        }
    }
    string t = s;
    if (int(unique(t.begin(), t.end()) - t.begin()) > 1)
    {
        for (int i = 1; i < n; i ++)
        {
            if (s[i - 1] == 'W')
            {
                s[i - 1] = 'B';
                s[i] = (s[i] == 'W') ? 'B' : 'W';

                ans1.pb(i);
            }
        }
    }

    cout << ans1.size() << endl;
    for (size_t i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;
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