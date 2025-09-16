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
    vector<string> s(10);
    for (auto &x : s)
        cin >> x;

    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (s[i][j] == 'X')
            {
                if (i == 0 || j == 0 || i == 9 || j == 9)
                    ans += 1;
                else if (i == 1 || j == 1 || i == 8 || j == 8)
                    ans += 2;
                else if (i == 2 || j == 2 || i == 7 || j == 7)
                    ans += 3;
                else if (i == 3 || j == 3 || i == 6 || j == 6)
                    ans += 4;
                else
                    ans += 5;
            }
        }
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