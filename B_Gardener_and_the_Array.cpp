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

    map<int, int> m;
    vi p[n];

    for (size_t i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        p[i].resize(k);
        for (size_t j = 0; j < k; j++)
        {
            cin >> p[i][j];

            m[p[i][j]]++;
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        bool yes = true;
        for (auto x : p[i])
        {
            if (m[x] == 1)
            {
                yes = false;
            }
        }
        if (yes)
        {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
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