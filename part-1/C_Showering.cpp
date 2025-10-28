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
    int n , m , s;
    cin >> n >> s >> m;

    vector <pii> a(n + 2);
    a[0] = {0 , 0};
    a[n + 1] = {m , m};
    
    for (int i = 1 ; i <= n ; i ++)
        cin >> a[i].F >> a[i].S;

    sort(all(a));

    for (int i = 1 ; i <= n + 1 ; i ++)
    {
        if (a[i].F - a[i - 1].S >= s)
        {
            cout << "YES" << endl;
            return ;
        }
    }

    cout << "NO" << endl;
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