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
    int n, k;
    cin >> n >> k;

    vector<string> s(n);
    for (auto &x : s)
        cin >> x;

    int line = 0;

    for (int i = 0; i < n; i++)
    {
        if (line + s[i].size() <= k)
        {
            if (line != 0)
                cout << " ";
            line += s[i].size();
        }
        else
        {
            cout << endl;
            line = s[i].size();
        }

        cout << s[i];
    }

    cout << endl;
}

int main()
{
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}