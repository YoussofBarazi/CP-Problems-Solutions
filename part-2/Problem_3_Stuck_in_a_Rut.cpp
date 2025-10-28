#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define x first
#define y second
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

    vector<pi> E, N;
    vector<int> indN, indE, ans(n, 2e9);
    for (int i = 0; i < n; i++)
    {
        char c;
        int X, Y;
        cin >> c >> X >> Y;

        if (c == 'E')
            E.pb({X, Y}), indE.pb(i);
        else
            N.pb({X, Y}), indN.pb(i);
    }

    for (int i = 0; i < E.size(); i++)
    {
        int mn = 2e9;
        for (int j = 0; j < N.size(); j++)
        {
            if (N[j].y > E[i].y || N[j].x < E[i].x)
                continue;
            if (N[j] == E[i])
                continue;

            int X = max(E[i].x, N[j].x), Y = max(E[i].y, N[j].y);
            int d1 = X - E[i].x, d2 = Y - N[j].y;

            bool crossed = false;

            for (int k = 0; k < E.size(); k++)
            {
                if (N[j].y > E[k].y || N[j].x < E[k].x)
                    continue;
                if (N[j] == E[k])
                    continue;

                int X2 = max(E[k].x, N[j].x), Y2 = max(E[k].y, N[j].y);
                int d11 = X2 - E[k].x, d22 = Y2 - N[j].y;

                if (d11 < d22 && Y2 < Y && X == X2)
                {
                    crossed = true;
                    break;
                }
            }

            if (d1 > d2 && !crossed)
                mn = min(mn, d1);
        }

        ans[indE[i]] = mn;
    }

    for (int i = 0; i < N.size(); i++)
    {
        int mn = 2e9;
        for (int j = 0; j < E.size(); j++)
        {
            if (N[i].y > E[j].y || N[i].x < E[j].x)
                continue;
            if (N[i] == E[j])
                continue;

            int X = max(E[j].x, N[i].x), Y = max(E[j].y, N[i].y);
            int d1 = X - E[j].x, d2 = Y - N[i].y;

            bool crossed = false;

            for (int k = 0; k < N.size(); k++)
            {
                if (N[k].y > E[j].y || N[k].x < E[j].x)
                    continue;
                if (N[k] == E[j])
                    continue;

                int X2 = max(E[j].x, N[k].x), Y2 = max(E[j].y, N[k].y);
                int d11 = X2 - E[j].x, d22 = Y2 - N[k].y;

                if (d11 > d22 && Y2 == Y && X > X2)
                {
                    crossed = true;
                    break;
                }
            }

            if (d1 < d2 && !crossed)
                mn = min(mn, d2);
        }

        ans[indN[i]] = mn;
    }

    for (auto x : ans)
    {
        if (x != 2e9)
            cout << x << endl;
        else
            cout << "Infinity" << endl;
    }
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