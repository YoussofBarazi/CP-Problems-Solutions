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
    string s[3];
    for (size_t i = 0; i < 3; i++)
    {
        cin >> s[i];
    }

    map<char, int> m;
    for (size_t i = 0; i < 3; i++)
    {
        int cnt = 0;
        for (size_t j = 1; j < 3; j++)
        {
            if (s[i][j] == s[i][j - 1] && s[i][j] != '.')
                cnt++;
        }

        if (cnt == 2)
            m[s[i][0]]++;

        cnt = 0;
        for (size_t j = 1; j < 3; j++)
        {
            if (s[j][i] == s[j - 1][i] && s[j][i] != '.')
                cnt++;
        }

        if (cnt == 2)
            m[s[0][i]]++;
    }

    if (s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[0][0] != '.')
        m[s[0][0]]++;
    if (s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[2][0] != '.')
        m[s[2][0]]++;

    string ans = "";
    if (m['X'] == m['+'] && m['+'] == m['O'])
        ans = "DRAW";
    else if (m['X'] == max({m['X'], m['O'], m['+']}))
        ans = "X";
    else if (m['O'] == max({m['X'], m['O'], m['+']}))
        ans = "O";
    else if (m['+'] == max({m['X'], m['O'], m['+']}))
        ans = "+";

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