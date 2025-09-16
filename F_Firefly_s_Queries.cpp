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
    int n , q;
    cin >> n >> q;

    vector <ll> sum(2 * n + 1 , 0);
    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> sum[i];
        sum[i + n] = sum[i]; 
        sum[i] += sum[i - 1];
    }
    for (int i = n + 1 ; i <= 2 * n ; i ++)
    {
        sum[i] += sum[i - 1];
    }

    while (q --)
    {
        ll l , r;
        cin >> l >> r;

        l -- , r --;

        int cycle1 = l / n;
        int cycle2 = r / n;
        
        l = l % n + 1 + cycle1;  
        r = r % n + 1 + cycle2;  

        cout << sum[n] * (cycle2 - cycle1 + 1) - (sum[l - 1] - sum[cycle1]) - (sum[cycle2 + n] - sum[r]) << endl;
    }
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}