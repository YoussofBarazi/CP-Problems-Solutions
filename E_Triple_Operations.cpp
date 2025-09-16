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

int cnt[N] , sum[N];

void solve()
{
    int l , r;
    cin >> l >> r;

    cout << sum[r] - sum[l - 1] + cnt[l] << endl;
}

int main()
{
    IOS;

    for (int i = 1 ; i <= 2e5 ; i ++)
    {
        int t = i;

        while (t > 0)
        {
            t /= 3;
            cnt[i] ++;
        }

        sum[i] = cnt[i] + sum[i - 1];
    }

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}