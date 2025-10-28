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
    ll n, k;
    scanf("%lld %lld", &n, &k);

    vl a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    int i = 0, j = 0;
    map<ll, int> s;
    ll ans = 0;

    while (j < n)
    {
        s[a[j]]++;

        auto mx = s.end(), mn = s.begin();
        if (s.size())
            mx--;

        while (s.size() && mx->F - mn->F > k)
        {
            s[a[i]]--;

            if (s[a[i]] == 0)
                s.erase(a[i]);

            i++;
            if (s.size() == 0)
                break;

            mx = s.end(), mx--, mn = s.begin();
        }

        ans += j - i + 1;
        j++;
    }
    printf("%lld", ans);
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