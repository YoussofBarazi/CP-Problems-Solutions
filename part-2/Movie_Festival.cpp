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

    vector<pair<int ,int>> movies(n);

    for (auto &x : movies)
    {
        cin >> x.S >> x.F;
    }

    sort(all(movies));

    int ans = 0;
    int last_movie_end = 0;

    for (auto x : movies)
    {
        if (x.S >= last_movie_end)
        {
            ans ++;
            last_movie_end = x.F;
        }
    }

    cout << ans << endl;
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