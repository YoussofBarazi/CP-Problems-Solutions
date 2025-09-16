#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 1000009;

int parent[N], Size[N];
int get(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}
bool join(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
        return false;

    if (Size[a] < Size[b])
        swap(a, b);

    parent[b] = a;

    Size[a] += Size[b];

    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (auto &x : s)
        cin >> x;

    vector<vector<int>> id;

    int c = 0;

    for (int i = 0; i < n; i++)
    {
        id.push_back({});

        for (int j = 0; j < m; j++)
        {
            parent[c] = c;
            Size[c] = 1;
            id[i].push_back(c++);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] != '#')
                continue;

            if (i > 0 && s[i - 1][j] == '#')
                join(id[i][j], id[i - 1][j]);
            if (j > 0 && s[i][j - 1] == '#')
                join(id[i][j], id[i][j - 1]);
            if (i + 1 < n && s[i + 1][j] == '#')
                join(id[i][j], id[i + 1][j]);
            if (j + 1 < m && s[i][j + 1] == '#')
                join(id[i][j], id[i][j + 1]);
        }
    }

    /*for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j ++)
        {
            cout << Size[get(id[i][j])] << " ";
        }
        cout << endl;
    }*/

    int ans = 0;

    vector<bool> add(n * m, true);

    for (int i = 0; i < n; i++)
    {
        int res = 0;
        vector<int> update;

        for (int j = 0; j < m; j++)
        {
            int p = get(id[i][j]);

            if (add[p])
            {
                add[p] = false;
                res += Size[p];
                update.push_back(p);
            }

            int p1 = -1, p2 = -1;

            if (i > 0 && s[i - 1][j] == '#')
            {
                p1 = get(id[i - 1][j]);

                if (add[p1])
                    res += Size[p1], add[p1] = false, update.push_back(p1);
            }
            if (i + 1 < n && s[i + 1][j] == '#')
            {
                p2 = get(id[i + 1][j]);

                if (add[p2])
                    res += Size[p2], add[p2] = false, update.push_back(p2);
            }
        }

        for (auto p : update)
            add[p] = true;

        ans = max(ans, res);
    }

    for (int j = 0; j < m; j++)
    {
        int res = 0;
        vector<int> update;

        for (int i = 0; i < n; i++)
        {
            int p = get(id[i][j]);

            if (add[p])
            {
                res += Size[p];
                add[p] = false;
                update.push_back(p);
            }

            int p1 = -1, p2 = -1;

            if (j > 0 && s[i][j - 1] == '#')
            {
                p1 = get(id[i][j - 1]);

                if (add[p1])
                    res += Size[p1], add[p1] = false, update.push_back(p1);
            }
            if (j + 1 < m && s[i][j + 1] == '#')
            {
                p2 = get(id[i][j + 1]);

                if (add[p2])
                    res += Size[p2], add[p2] = false, update.push_back(p2);
            }
        }

        for (auto p : update)
            add[p] = true;

        ans = max(ans, res);
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}