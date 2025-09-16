#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define s first
#define e second
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
    int n;
    cin >> n;

    vector <pair <int , int>> m;

    for (int i = 0 ; i < n ; i ++)
    {
        int x , y;
        cin >> x >> y;

        m.pb({x - y , x + y});
    }

    sort(all(m) , [](pair <int , int> &p1 , pair <int , int> &p2){
    
        if (p1.s != p2.s)
            return p1.s < p2.s;
        
        return p1.e > p2.e;
    }
    );

    int ans = 0 , mx = -1;

    for (int i = 0 ; i < n ; i ++)
    {
        if (mx < m[i].e)
            mx = m[i].e , ans ++;
    }

    cout << ans << endl;
}

int main()
{
    freopen("mountains.in" , "r" , stdin);
    freopen("mountains.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}