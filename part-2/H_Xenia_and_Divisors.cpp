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

    vi a(n);
    map<int, int> m;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }

    vector<set<int>> ans(n / 3);

    for (size_t x = 0; x < n / 3; x++)
    {
        for (size_t i = 1; i < 8; i++)
        {
            bool ok = false;
            if (m[i] > 0)
            for (size_t j = i + 1; j < 8; j++)
            {
                if (m[j] > 0 && j % i == 0)
                for (size_t k = j + 1; k < 8; k++)
                {
                    if (m[k] > 0 && k % j == 0)
                    {
                        ans[x].insert(i);
                        ans[x].insert(j);
                        ans[x].insert(k);
                        m[i] --;
                        m[j] --;
                        m[k] --;
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) break;
        }
        if (ans[x].size() != 3)
        {
            cout << "-1" << endl;
            return;
        }
    }

    for (size_t i = 0; i < n / 3; i++)
    {
        for (auto x : ans[i])
            cout << x << " ";
        cout << endl;
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