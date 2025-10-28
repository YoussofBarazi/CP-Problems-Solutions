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
    int n , k;
    cin >> n >> k;

    vector <vector <int>> a(n);

    for (auto &x : a)
    {
        x.resize(n);

        for (auto &y : x)
            cin >> y;
    }

    int ans = 0;

    for (int i = k - 1 ; i < n ; i ++)
    {
        for (int j = k - 1 ; j < n ; j ++)
        {
            int t = a[i][j];

            if (a[i - k + 1][j] == t && a[i][j - k + 1] == t && a[i - k + 1][j - k + 1] == t)
                ans ++;
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