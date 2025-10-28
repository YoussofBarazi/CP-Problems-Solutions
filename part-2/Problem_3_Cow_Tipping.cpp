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

void flipe(vector<string> &s, int r, int c)
{
    for (int i = 0; i <= r; i++)
        for (int j = 0; j <= c; j++)
            s[i][j] = (s[i][j] == '1') ? '0' : '1';
}

void solve()
{
    int n;
    cin >> n;

    vector<string> s(n);
    for (string &x : s)
        cin >> x;

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (s[i][j] == '1')
            {
                flipe(s, i, j);
                cnt++;
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