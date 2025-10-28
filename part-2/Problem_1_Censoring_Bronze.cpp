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
    string s, t;
    cin >> s >> t;

    string ans = "";
    int n = s.size(), m = t.size();

    for (int i = 0; i < n; i++)
    {
        ans += s[i];

        int j = int(ans.size()) - m, k = 0;

        while (j >= 0 && k < m && ans[j] == t[k])
        {
            k++, j++;
        }

        if (k == m)
        {
            while (k > 0)
                ans.pop_back(), k--;
        }
    }

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