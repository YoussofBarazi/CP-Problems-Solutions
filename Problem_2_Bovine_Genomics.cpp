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

    vector<string> s(n * 2);
    for (int i = 0; i < n * 2; i++)
    {
        cin >> s[i];
    }

    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                set<string> g;

                for (int w = 0; w < n; w++)
                {
                    string t = "";
                    t += s[w][i] + s[w][j] + s[w][k];
                    sort(all(t));
                    g.insert(t);
                }

                bool ok = true;

                for (int w = n; w < 2 * n; w++)
                {
                    string t = "";
                    t += s[w][i] + s[w][j] + s[w][k];
                    sort(all(t));
                    if (g.find(t) != g.end())
                    {
                        ok = false;
                        break;
                    }
                }

                cnt += ok;
            }
        }
    }

    cout << cnt << endl;
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