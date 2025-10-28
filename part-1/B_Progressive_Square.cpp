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

const int N = 509;

ll b[N][N];

void solve()
{
    ll n, c, d;
    cin >> n >> c >> d;

    vector<ll> a(n * n);

    map<ll, int> freq;

    for (auto &x : a)
    {
        cin >> x;
        freq[x]++;
    }

    b[0][0] = freq.begin()->first;
    freq.begin()->second--;

    vector <vector<bool>> ok(n , vector <bool> (n , false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 1 < n && !ok[i + 1][j])
            {
                b[i + 1][j] = b[i][j] + c;
                freq[b[i + 1][j]]--;
                ok[i + 1][j] = true;
            }

            if (j + 1 < n && !ok[i][j + 1])
            {
                b[i][j + 1] = b[i][j] + d;
                freq[b[i][j + 1]]--;
                ok[i][j + 1] = true;
            }
        }
    }

    for (auto x : freq)
    {
        if (x.S != 0)
        {
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
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