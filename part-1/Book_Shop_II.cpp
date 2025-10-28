#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

void solve()
{
    int n , x;
    cin >> n >> x;

    vector <int> price(n) , pages(n) , copies(n);
    
    for (auto &x : price)
        cin >> x;
    for (auto &x : pages)
        cin >> x;
    for (auto &x : copies)
        cin >> x;

    vector <pii> g(n);

    for (int i = 0 ; i < n ; i ++)
    {
        int tmp = copies[i] , c = 1;

        while (tmp > c)
        {
            tmp -= c;
            g.push_back({price[i] * c , pages[i] * c});
            c *= 2;
        }

        g.push_back({price[i] * tmp , pages[i] * tmp});

    }

    vector <int> dp(x + 10 , 0);

    n = g.size();

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = x ; j >= 0 ; j --)
        {
            if (g[i].F <= j)
                dp[j] = max(dp[j] , dp[j - g[i].F] + g[i].S);
        }
    }

    cout << dp[x] << endl;
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