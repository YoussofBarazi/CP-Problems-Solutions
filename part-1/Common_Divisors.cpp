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
    int n;
    scanf("%d", &n);

    vi freq(1e6 + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);

        freq[a]++;
    }

    for (int gcd = 1e6; gcd > 0; gcd--)
    {
        int occ = 0;
        for (int i = gcd; i <= 1e6; i += gcd)
        {
            occ += freq[i];
            if (occ >= 2)
            {
                printf("%d", gcd);
                return;
            }
        }
    }
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