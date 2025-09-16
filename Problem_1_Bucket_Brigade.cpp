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

string get()
{
    char c[11];
    scanf("%s", c);

    return c;
}

void solve()
{
    vector<string> s(10);

    int x1, y1, x2, y2, x3, y3;
    for (int i = 0; i < 10; i++)
    {
        s[i] = get();

        for (int j = 0; j < 10; j++)
        {
            if (s[i][j] == 'L')
                x1 = i, y1 = j;
            if (s[i][j] == 'B')
                x2 = i, y2 = j;
            if (s[i][j] == 'R')
                x3 = i, y3 = j;
        }
    }

    int ans = abs(x1 - x2) + abs(y1 - y2) - 1;

    if ((x1 == x2 && x2 == x3 && max(y1, y2) > y3 && y3 > min(y1, y2)) || (y1 == y2 && y2 == y3 && max(x1, x2) > x3 && x3 > min(x1, x2)))
        ans += 2;

    printf("%d\n", ans);
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