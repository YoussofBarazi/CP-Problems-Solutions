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

        while (p != 0 && s[i] != s[p])
        {
            p = ans[p - 1];
        }

        if (s[i] == s[p])
            p++;

        ans[i] = p;
    }

    return ans.back();
}

void solve()
{
    string s;
    cin >> s;

    int i = 0, n = s.size();
    string a = "", b = "";

    while (i < n - 1 && s[i] == s[n - i - 1])
        a.pb(s[i]), b.pb(s[i]), i++;

    if (i >= n / 2)
    {
        cout << s << endl;
        return;
    }

    reverse(all(b));

    if (i != 0)
        s = s.substr(i, n - 2 * i);
    // cout << s << endl;

    string t = s;

    reverse(all(t));

    int len1 = KMP(s + '$' + t), len2 = KMP(t + '$' + s);

    string ans = a;

    if (len1 >= len2)
        ans += s.substr(0, len1);
    else
        ans += t.substr(0, len2);

    ans += b;

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