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
    string s[3];
    for (int i = 0; i < 3; i++)
        cin >> s[i];

    for (int i = 0; i < 3; i++)
    {
        vector<int> f(3, 0);
        for (int j = 0; j < 3; j++)
        {
            if (s[i][j] != '?')
                f[s[i][j] - 'A']++;
        }

        if (f[0] == 0)
        {
            cout << 'A' << endl;
            return;
        }
        if (f[1] == 0)
        {
            cout << 'B' << endl;
            return;
        }
        if (f[2] == 0)
        {
            cout << 'C' << endl;
            return;
        }
    }
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