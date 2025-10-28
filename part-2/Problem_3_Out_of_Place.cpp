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
    int n;
    cin >> n;

    vector<int> a(n + 2);
    a[0] = 0, a[n + 1] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ind = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
            ind = i;
    }

    vector<int> b = a;
    int cnt = 0, i = ind - 1;
    while (i > 0 && a[i] > a[ind])
    {
        cnt++;
        while (a[i] == a[i - 1])
            i--;
        swap(a[i], a[ind]);
        ind = i;
        i--;
    }

    if (!is_sorted(all(a)))
    {
        a = b;

        for (int i = 1; i <= n; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
                ind = i;
        }

        cnt = 0, i = ind + 1;
        while (i <= n && a[i] < a[ind])
        {
            cnt++;
            while (a[i] == a[i + 1])
                i++;

            i++;
        }
    }

    cout << cnt << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}