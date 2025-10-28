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

ll a[N] , cnt2 = 0 , b[N] , tmp = 0;
int n;

bool ok(int x)
{
    int count = 0;
    tmp = cnt2;

    for (int i = n - 1 ; i >= 0 ; i --)
    {
        ll t = a[i];
        while (tmp > 0 && t < x)
            tmp -- , t *= 2; 

        if (t >= x)
            count ++;

        if (count >= x)
            return true;
    }

    return false;
}

void solve()
{
    cin >> n;

    cnt2 = 0;

    for (int i = 0 ; i < n ; i ++)
    {    
        cin >> a[i];

        while (a[i] % 2 == 0)
            a[i] /= 2 , cnt2 ++;
    }

    sort(a , a + n);

    int l = 1 , r = n;

    while (l < r)
    {
        int mid = (l + r + 1) >> 1;

        if (ok(mid))
            l = mid;
        else 
            r = mid - 1;
    }

    cout << l << endl;
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