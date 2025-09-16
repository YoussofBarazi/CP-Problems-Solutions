#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

int d[N];
int n , T;

bool ok (int k)
{
    priority_queue<int, vector<int>, greater<int>> q;

    int i = 0;
    for (; i < k ; i ++)
    {
        q.push(d[i]);
    }

    int t = 0;
    while (i < n)
    {
        while (q.size() && q.top() == t)
        {
            q.pop();
            
            if (i < n)
                if (t + d[i] > T)
                    return false;
                else 
                    q.push(t + d[i ++]);
        }

        t ++;
    }

    return i == n;
}

void solve()
{
    cin >> n >> T;

    for (int i = 0 ; i < n ; i ++)
        cin >> d[i];

    int l = 1 , r = n;
    
    while (l < r)
    {
        int mid = (l + r) / 2;

        if (ok(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << endl;
}

int main()
{
    freopen("cowdance.in" , "r" , stdin);
    freopen("cowdance.out" , "w" , stdout);
    
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}