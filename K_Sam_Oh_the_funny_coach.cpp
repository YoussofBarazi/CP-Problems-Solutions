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

char ch[999999];
string getString()
{
    scanf("%s", &ch);
    return ch;
}

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<string> s(n);
    for (auto &x : s)
        x = getString();

    map<pair<int, int>, int> mem;

    int q;
    scanf("%d", &q);

    while (q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);

        l--, r--;

        if (l > r)
            swap(l, r);

        if (mem.find({l, r}) != mem.end())
        {
            printf("%d\n", mem[{l, r}]);
            continue;
        }

        int cnt = 0;

        for (int i = 0; i < m; i++)
            cnt += s[l][i] == s[r][i];

        printf("%d\n", cnt);

        mem[{l, r}] = cnt;
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