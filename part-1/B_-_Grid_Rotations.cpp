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
    int n, m;
    cin >> n >> m;

    vector<string> s(n + 1);

    for (size_t i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    
    pi r1 = {0, 0}, r2 = {0, 0}, r3 = {0, 0}, r4 = {0, 0};

    int q;
    cin >> q;

    for (size_t i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        r1 = {abs(r1.F - a - 1), abs(r1.S - b - 1)};
        r2 = {abs(r2.F - a - 1), abs(r2.S - b - m - 1)};
        r3 = {abs(r3.F - a - n - 1), abs(r3.S - b - 1)};
        r4 = {abs(r4.F - a - n - 1), abs(r4.S - b - m - 1)};

        if (i == q - 1)
        {
            for (int i = 1; i <= a; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (j <= b)
                    {
                        cout << s[abs(i - r1.F)][abs(j - r1.S)];
                    }
                    else
                    {
                        cout << s[abs(i - r2.F)][abs(j - r2.S)];
                    }
                }
                cout << endl;
            }
            for (int i = a + 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (j <= b)
                    {
                        cout << s[abs(i - r3.F)][abs(j - r3.S)];
                    }
                    else
                    {
                        cout << s[abs(i - r4.F)][abs(j - r4.S)];
                    }
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}