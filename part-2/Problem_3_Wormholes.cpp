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

int n, x[N], y[N], partner[N], nxt[N];

bool ok()
{
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        for (int w = 0; w < 20; w++)
            x = nxt[partner[x]];

        if (x)
            return true;
    }

    return false;
}

int O_O()
{
    int i = 1;
    while (i <= n && partner[i])
        i++;

    if (i > n)
        return ok();

    int ans = 0;

    for (int j = i + 1; j <= n; j++)
    {
        if (partner[j])
            continue;

        partner[i] = j;
        partner[j] = i;

        ans += O_O();

        partner[i] = partner[j] = 0;
    }

    return ans;
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[j] > x[i] && y[i] == y[j])
                if (nxt[i] == 0 || x[j] - x[i] < x[nxt[i]] - x[i])
                    nxt[i] = j;
        }
    }

    cout << O_O() << endl;
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