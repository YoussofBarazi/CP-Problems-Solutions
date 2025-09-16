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
    string s[8];
    for (int i = 0; i < 8; i++)
        cin >> s[i];

    vector<int> col(8);
    iota(all(col), 0);

    int ans = 0;
    do
    {
        bool ok = true;

        for (int i = 0; i < 8; i++)
            ok &= (s[i][col[i]] == '.');

        for (int i = 0; i < 8; i++)
            for (int j = i + 1; j < 8; j++)
                ok &= (col[i] + i != col[j] + j && col[i] - i != col[j] - j);

        ans += ok;
    } while (next_permutation(all(col)));

    cout << ans << endl;
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