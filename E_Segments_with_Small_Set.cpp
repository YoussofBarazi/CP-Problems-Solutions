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
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    if (k == 0)
    {
        cout << 0 << endl;
        return;
    }

    map<int, int> unique;

    int i = 1, j = 1;
    ll ans = 0;

    while (j <= n)
    {
        unique[a[j]]++;

        while (k < unique.size())
        {
            unique[a[i]]--;

            if (unique[a[i]] == 0)
                unique.erase(a[i]);
            i++;
        }

        if (unique.size() <= k)
        {
            ans += j - i + 1;
        }
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