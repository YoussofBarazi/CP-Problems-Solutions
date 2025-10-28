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

const int N = 400009;

int a[N] , GPF[N];
vector <set<int>> d(N);
vector <vi> ndx(N);

void precalc()
{
    for (int i = 2 ; i < N ; i ++)
        if (!GPF[i])
            for (int j = i ; j < N ; j += i)
                GPF[j] = i;
}

ll DP[N];
int n , k;

ll dp(int i)
{
    if (i >= n - 1)
        return 0;

    ll &ret = DP[i];

    if (ret != -1)
        return ret;

    ret = dp(i + 1) + gcd(a[i] , a[i + 1]);
    
    for (int g : d[a[i]])
    {
        auto j = upper_bound(all(ndx[g]) , i);

        if (j != ndx[g].end() && *j - i <= k)
        {       
            ret = max(ret , dp(*j) + gcd(a[*j] , a[i]));
        }
    }

    return ret;
}

void solve()
{
    cin >> n >> k;

    map <int , int> dist; 
    
    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        a[i] = x;
        dist[x] ++;
        
        while (x > 1)
        {
            int g = GPF[x];
            ndx[g].push_back(i);
            d[a[i]].insert(g);
            
            while (x % g == 0)
                x /= g;
        }
    }

    for (int i = 0 ; i < n ; i ++)
        DP[i] = -1;

    cout << dp(0) << endl;

    for (auto x : dist)
    {
        ndx[x.F].clear();
        d[x.F].clear();
    }
}

int main()
{
    IOS;

    precalc();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}