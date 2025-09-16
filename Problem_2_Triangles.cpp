#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 20001;

void solve()
{
    int n;
    cin >> n ; 

    vector <vector<ll>> X(2e4 + 1) , Y(2e4 + 1) , sumX , sumY;

    vector <pair<int , int>> point;

    for (int i = 0 ; i < n ; i ++)
    {
        int x , y;
        cin >> x >> y;

        x += 1e4 + 1 , y += 1e4 + 1;

        X[x].pb(y);
        Y[y].pb(x);

        point.pb({x , y});
    }

    for (auto &w : X)
    {
        sort(all(w));
    }
    for (auto &w : Y)
    {
        sort(all(w));
    }
    sumX = X , sumY = Y;

    for (auto &x : sumX)
    {
        for (int i = 1 ; i < x.size() ; i ++)
            x[i] += x[i - 1];
    }
    for (auto &y : sumY)
    {
        for (int i = 1 ; i < y.size() ; i ++)
            y[i] += y[i - 1];
    }

    ll ans = 0 , mod = 1e9 + 7;

    for (auto p : point)
    {
        ll cntl = 0 , cntr = 0 , suml = 0 , sumr = 0;        

        int ind = lower_bound(all(Y[p.S]) , p.F) - Y[p.S].begin();

        if (ind != 0)
            suml = sumY[p.S][ind - 1] , cntl = ind;    

        sumr = sumY[p.S].back() - sumY[p.S][ind] , cntr = sumY[p.S].size() - ind - 1;

        ll base = sumr - suml - (cntr - cntl) * p.F;

        ll cnta = 0 , cntu = 0 , suma = 0 , sumu = 0;

        ind = lower_bound(all(X[p.F]) , p.S) - X[p.F].begin(); 

        if (ind != 0)
            sumu = sumX[p.F][ind - 1] , cntu = ind;    

        suma = sumX[p.F].back() - sumX[p.F][ind] , cnta = sumX[p.F].size() - ind - 1;

        ll hight = suma - sumu - (cnta - cntu) * p.S;

        ans += base * hight % mod;
    }

    cout << ans % mod << endl;
}

int main()
{
    freopen("triangles.in" , "r" , stdin);
    freopen("triangles.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}