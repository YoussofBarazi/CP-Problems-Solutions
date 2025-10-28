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
    int c[3], m[3];

    scanf("%d%d", &c[0], &m[0]);
    scanf("%d%d", &c[1], &m[1]);
    scanf("%d%d", &c[2], &m[2]);

    pair<int, int> op[3];

    op[0] = {0, 1};
    op[1] = {1, 2};
    op[2] = {2, 0};

    int ind = 0;
    for (int i = 0; i < 100; i++)
    {
        ind = i % 3;
        int x = op[ind].F, y = op[ind].S;

        int v = min(m[x], c[y] - m[y]);
        m[x] -= v;
        m[y] += v;
    }

    printf("%d\n%d\n%d\n", m[0], m[1], m[2]);
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