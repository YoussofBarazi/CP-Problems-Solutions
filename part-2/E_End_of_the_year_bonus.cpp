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
ll n, b;

void calc(vector<ll> &bonus, vector<ll> per)
{
    int n = per.size();

    ll cnt = per[0] > 0;
    bonus[0] = max(bonus[0], cnt);

    for (int i = 0; i < n << 1; i++)
    {
        int ind = i % n,
            right = (i + 1) % n;

        if (per[ind] < per[right])
            cnt++;
        else
            cnt = per[right] > 0;

        bonus[right] = max(bonus[right], cnt);
    }

    cnt = per[n - 1] > 0;
    bonus[n - 1] = max(bonus[n - 1], cnt);

    for (int i = (n << 1) - 1; i >= 0; i--)
    {
        int ind = i % n,
            left = (i - 1 + n) % n;

        if (per[ind] < per[left])
            cnt++;
        else
            cnt = per[left] > 0;

        bonus[left] = max(bonus[left], cnt);
    }
}

void solve()
{
    cin >> n >> b;

    vector<ll> per(n);
    for (auto &x : per)
        cin >> x;

    vector<ll> bonus(n, 0);

    calc(bonus, per);

    for (int i = 0; i < n; i++)
    {
        cout << bonus[i] * b;
        if (i < n - 1)
            cout << " ";
        else
            cout << endl;
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