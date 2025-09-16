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
    int n , w;
    cin >> n >> w;

    int mx = -1e9 , mn = 1e9 , sum = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        sum += x;
        mx = max(mx , sum);
        mn = min(mn , sum);
    }

    w ++;
    if (mx > 0)
        w -= mx;
    if (mn < 0)
        w += mn;
    
    cout << max(w , 0) << endl;
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