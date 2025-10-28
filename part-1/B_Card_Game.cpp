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
    int a1 , a2 , b1 , b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int ans = 0;

    if (a1 > b1 && a2 >= b2 || a1 >= b1 && a2 > b2) ans ++;
    if (a1 > b2 && a2 >= b1 || a1 >= b2 && a2 > b1) ans ++;
    if (a2 > b1 && a1 >= b2 || a2 >= b1 && a1 > b2) ans ++;
    if (a2 > b2 && a1 >= b1 || a2 >= b2 && a1 > b1) ans ++;

    cout << ans << endl;
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