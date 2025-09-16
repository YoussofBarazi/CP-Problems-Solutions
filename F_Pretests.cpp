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

bool cmp(const pi a, const pi b)
{
    if (a.F != b.F)
        return a.F > b.F;

    return a.S < b.S;
}

string get_string()
{

    const int N = 2e5 + 7;
    char s[N];

    scanf("%s", s);

    return s;
}

void solve()
{
    int t, n;
    scanf("%d %d", &n, &t);

    vector<string> s(t);
    map<int, int> m;
    vector<pi> ans;

    for (int i = 0; i < t; i++)
    {
        s[i] = get_string();
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == '0')
                m[j + 1]++;

            if (!m.count(j + 1))
                m[j + 1] = 0;
        }
    }

    for (auto x : m)
        ans.pb({x.S, x.F});

    sort(all(ans), cmp);

    ll runs = 0;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][ans[j].S - 1] == '0')
            {
                runs += j + 1;
                break;
            }
        }
    }

    printf("%d\n", runs);

    for (auto x : ans)
        printf("%d ", x.S);
}

int main()
{
    freopen("tests.in", "r", stdin);

    int t = 1;
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    return 0;
}