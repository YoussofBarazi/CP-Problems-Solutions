#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

bool is_cons(char c)
{
    return c != 'e' && c != 'a';
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    string ans = "";
    bool hasC = false;
    for (int i = 0; i < n; i++)
    {
        if (is_cons(s[i]))
        {
            if (i + 1 < n && is_cons(s[i + 1])) // CVC.C
                ans += s[i] , ans += '.' , hasC = false;
            else  // CV
            {
                if (hasC && i != n - 1)
                    ans += '.';
                ans += s[i];
                hasC = true;
            }
        }
        else
            ans += s[i];
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}