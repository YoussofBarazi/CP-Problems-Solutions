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
    string s;
    cin >> s;

    int ans = (s[0] != '0') ? s[0] - '0' : 10;

    for (int i = 1; i < s.size(); i++)
    {
        ans += abs(((s[i - 1] != '0') ? s[i - 1] - '0' : 10) - ((s[i] != '0') ? s[i] - '0' : 10)) + 1;
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