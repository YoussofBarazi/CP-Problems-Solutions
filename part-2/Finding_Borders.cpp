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

vector<int> KMP(string s)
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

    return ans;
}

void solve()
{
    string s;
    cin >> s;

    vector<int> kmp = KMP(s), ans;

    int p = kmp[s.size() - 1];

    while (p > 0)
    {
        ans.pb(p);
        p = kmp[p - 1];
    }

    sort(all(ans));

    for (auto x : ans)
        cout << x << " ";
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