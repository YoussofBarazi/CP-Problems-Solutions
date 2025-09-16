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

ll calc(ll first , ll last , ll sz)
{
    return ((first + last) * sz) / 2;
}

int n , k;

ll diff(int i)
{
    return calc(k , k + i - 1 , i) - calc(k + i , k + n - 1 , n - i);
}

void solve()
{
    cin >> n >> k;
    int l = 1 , r = n; 

    while (l < r)
    {
        int mid = (l + r + 1) / 2;

        if (diff(mid) < 0)
            l = mid;
        else 
            r = mid - 1;
    }

    ll mn = abs(diff(l));

    for (int i = l - 1000 ; i <= l + 1000 ; i ++)
    {
        mn = min(mn , abs(diff(i)));
    }

    cout << mn << endl;
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