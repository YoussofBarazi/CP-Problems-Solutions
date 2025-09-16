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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

ll arithmetic_progression(ll first, ll last, ll size)
{
    return ((first + last) * size) / 2;
}

void solve()
{
    string s;
    cin >> s;

    ll ans = 0 , cur = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        cur += (s[i] == '-')? -1 : 1;

        if (cur < 0) 
        {
            ans += i + 1;
            cur ++;
        }
    }
    ans += s.size();
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