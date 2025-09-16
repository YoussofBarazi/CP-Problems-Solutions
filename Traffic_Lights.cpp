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

const int N = 200009;

void solve()
{
    int n , l;
    cin >> l >> n;

    set <int> lights = {0 , l};
    set <pair<int , pair<int , int>>> q;

    while (n --)
    {
        int x;
        cin >> x;

        auto L = lights.upper_bound(x);
        auto R = L;
        
        if(x != 1)
            L --;

        auto p = q.find({*R - *L , {*L , *R}});

        if (p != q.end())
            q.erase(p);

        q.insert({*R - x , {x , *R}});
        q.insert({x - *L , {*L , x}});
        lights.insert(x);

        auto ans = q.end();
        ans --;

        cout << ans -> F << " ";
    }
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