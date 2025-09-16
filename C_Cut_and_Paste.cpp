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

char c[501];

string get()
{
    scanf("%s", c);
    return c;
}

void solve()
{
    ll x, mod = 1e9 + 7;
    scanf("%lld", &x);
    string s = get();

    string c = "";
    ll size = s.size();

    for (ll i = 0; i < x; i++)
    {
        if (s.size() < x && s[i] != '1')
        {
            c = s.substr(i + 1, s.size() - i - 1);

            if (s[i] == '2')
                s += c, c += c;
            else if (s[i] == '3')
                s += c + c, c += (c + c);
        }

        size += ((size - i - 1 + mod) * (s[i] - '1')) % mod;
        size %= mod;
    }

    printf("%lld\n", size);
}

int main()
{
    //    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}