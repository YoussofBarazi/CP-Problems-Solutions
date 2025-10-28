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

int KMP(string s)
{
    vector<int> ans(s.size(), 0);

    for (int i = 1; i < s.size(); i++)
    {
        int p = ans[i - 1];

        while (p != 0 && s[p] != s[i])
            p = ans[p - 1];

        if (s[p] == s[i])
            p++;

        ans[i] = p;
    }

    return ans.back();
}

void solve()
{
    int n;
    cin >> n;

    vector<string> s(n);
    for (auto &x : s)
        cin >> x;

    string ans = s[0];

    for (int i = 1; i < n; i++)
    {
        string t = ans.substr(ans.size() - min(ans.size(), s[i].size()));
        int len = KMP(s[i] + '$' + t);

        for (int j = len; j < s[i].size(); j++)
            ans += s[i][j];
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