#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
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
    cin >> n;

    vector<char> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> P(n + 1, 0), H(n + 1, 0), S(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        P[i + 1] = P[i] + (a[i] == 'P');
        H[i + 1] = H[i] + (a[i] == 'H');
        S[i + 1] = S[i] + (a[i] == 'S');
    }

    int ans = 0;
    // PS
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, H[i] + P[n] - P[i]);
    }
    // SP
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, P[i] + H[n] - H[i]);
    }
    // PH
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, H[i] + S[n] - S[i]);
    }
    // HP
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, S[i] + H[n] - H[i]);
    }
    // HS
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, S[i] + P[n] - P[i]);
    }
    // SH
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, P[i] + S[n] - S[i]);
    }

    cout << ans << endl;
}

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}