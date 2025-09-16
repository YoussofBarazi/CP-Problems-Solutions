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

bool is_digit(char c)
{
    return c - '0' >= 0 && c - '0' <= 9;
}

void solve()
{
    string s;
    int k;
    cin >> s >> k;

    int i = s.size() - 1;
    char c;
    string ans = "";

    while (i >= 0)
    {
        int num = 0;
        if (!is_digit(s[i]))
            c = s[i], i--;

        int pow10 = 1;
        while (i >= 0 && is_digit(s[i]))
        {
            num += (s[i] - '0') * pow10;
            pow10 *= 10;
            i--;
        }

        if (ans.size() + num > k)
        {
            cout << "unfeasible" << endl;
            return;
        }

        ans += string(max(num, 1), c);
    }

    reverse(all(ans));

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