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
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> leftZero(n, 0), rightOne(n, 0);

    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            ind = i + 1;
        leftZero[i] = ind;
    }

    ind = n + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            ind = i + 1;
        rightOne[i] = ind;
    }

    bool add = false;
    set<pair<int, int>> ans;

    while (m--)
    {
        int l, r;
        cin >> l >> r;

        l--, r--;

        int y = leftZero[r], x = rightOne[l];

        if (x >= y)
            add = true;
        else
            ans.insert({x, y});
    }

    cout << ans.size() + add << endl;
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