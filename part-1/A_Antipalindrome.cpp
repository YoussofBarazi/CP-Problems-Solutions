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
    string s;
    cin >> s;

    int cnt = 1;
    bool pal = true;
    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
        if (s[i] != s[s.size() - i - 1])
            pal = false;
    }

    if (!pal)
        cout << s.size() << endl;
    else if (cnt == s.size())
        cout << 0 << endl;
    else
        cout << s.size() - 1 << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}