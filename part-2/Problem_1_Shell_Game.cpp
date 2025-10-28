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
    scanf("%d", &n);

    vector<int> x1(3, 0), x2(3, 0), x3(3, 0);
    x1[0] = 1, x2[1] = 1, x3[2] = 1;

    int ans1 = 0, ans2 = 0, ans3 = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b, g;
        scanf("%d%d%d", &a, &b, &g);

        a--, b--, g--;

        swap(x1[a], x1[b]);
        swap(x2[a], x2[b]);
        swap(x3[a], x3[b]);

        ans1 += x1[g];
        ans2 += x2[g];
        ans3 += x3[g];
    }

    printf("%d\n", max({ans1, ans2, ans3}));
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