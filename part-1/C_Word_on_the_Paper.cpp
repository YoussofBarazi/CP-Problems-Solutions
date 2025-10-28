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
    vector<string> s(8);

    for (int i = 0; i < 8; i++)
        cin >> s[i];

    int x, y = -1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            if (s[i][j] <= 'z' && s[i][j] >= 'a')
            {
                x = i, y = j;
                break;
            }

        if (y != -1)
            break;
    }

    string ans = "";
    for (int i = x; i < 8; i++)
    {
        if (s[i][y] == '.')
            break;

        ans += s[i][y];
    }

    cout << ans << endl;
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